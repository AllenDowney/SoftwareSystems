/* Example code for Software Systems at Olin College.

Copyright 2012 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

Started with ex-ghashtable-3.c from
http://www.ibm.com/developerworks/linux/tutorials/l-glib/section5.html

*/

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <glib/gstdio.h>


/* Represents a word-frequency pair. */
typedef struct {
    gint freq;
    gchar *word;
} Pair;


/* Compares two key-value pairs by frequency. */
gint compare_pair (gpointer v1, gpointer v2, gpointer user_data)
{
    Pair *p1 = (Pair *) v1;
    Pair *p2 = (Pair *) v2;
    return p1->freq - p2->freq;
}


/* Iterator that prints pairs. */
void pair_printor (gpointer value, gpointer user_data)
{
    Pair *pair = (Pair *) value;
    printf ("%d\t %s\n", pair->freq, pair->word);
}


/* Iterator that prints keys and values. */
void kv_printor (gpointer key, gpointer value, gpointer user_data)
{
    printf (user_data, key, * (gint *) value);
}


/* Iterator that add key-value pairs to a sequence. */
void accumulator (gpointer key, gpointer value, gpointer user_data)
{
    GSequence *seq = (GSequence *) user_data;
    Pair *pair = g_new (Pair, 1);

    // make a copy of the key
    pair->word = g_strdup ((gchar *) key);
    pair->freq = * (gint *) value;

    g_sequence_insert_sorted (seq, 
			      (gpointer) pair, 
			      (GCompareDataFunc) compare_pair,
			      NULL);
}


/* Destructs an element of a sequence */
void pair_destructor (gpointer p)
{
    Pair *pair = (Pair *) p;
    g_free (pair->word);
    g_free (pair);
}


/* Increments the frequency associated with key. */
void incr (GHashTable* hash, gchar *word)
{
    gint *val = (gint *) g_hash_table_lookup (hash, word);

    if (val == NULL) {
	gchar *key = g_strdup (word);
	gint *val = g_new (gint, 1);
	*val = 1;
	g_hash_table_insert (hash, key, val);
    } else {
	*val += 1;
    }
}

int main (int argc, char** argv)
{
    gchar *filename;

    // open the file
    if (argc > 1) {
	filename = argv[1];
    } else {
	filename = "emma.txt";
    }

    FILE *fp = g_fopen(filename, "r");
    if (fp == NULL) {
	perror (filename);
	exit (-10);
    }
    /* string array is a (two-L) NULL terminated array of pointers to
       (one-L) NUL terminated strings */

    gchar **array;
    gchar line[128];

    GHashTable* hash = g_hash_table_new_full (g_str_hash, 
					      g_str_equal,
					      g_free,
					      g_free);

    int i;

    // read lines from the file and build the hash table
    while (1) {
	gchar *res = fgets (line, sizeof(line), fp);
	if (res == NULL) break;

	array = g_strsplit (line, " ", 0);
	for (i=0; array[i] != NULL; i++) {
	    incr (hash, array[i]);
	}
	g_strfreev (array);
    }
    fclose (fp);

    // print the hash table
    // g_hash_table_foreach (hash,  (GHFunc) kv_printor, "Word %s freq %d\n");

    // iterate the hash table and build the sequence
    GSequence *seq = g_sequence_new ((GDestroyNotify) pair_destructor);
    g_hash_table_foreach (hash,  (GHFunc) accumulator, (gpointer) seq);

    // iterate the sequence and print the pairs
    g_sequence_foreach (seq,  (GFunc) pair_printor, NULL);

    // free everything
    g_hash_table_destroy (hash);

    g_sequence_free (seq);
    
    return 0;
}
 
