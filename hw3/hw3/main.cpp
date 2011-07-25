//  Paul Reny - COMP 15 - 07/24/11
//  HW3
//  main.cpp
//
//  Copyright 2011 Reny Design. All rights reserved.
//
//
//
// Your job is to choose one of the data structures covered in class that can map a character string to a integer, with the objective of optimizing retrieval time. You are expected to justify your decision.
//
//
//

#include <iostream>
#include <string>
#include <cstdlib>
#include "ptrie.h"

using namespace std;

typedef ptrie<int,128,char> stopword_trie;

template <class TREE>
struct my_it : public TREE::iterator_callback
{
  bool operator() ( typename TREE::key_t *key, int len, typename TREE::value_t value )
  {
    if( value != 0)
    {
      for( int i=0; i<len; ++i)
      {
        cout << char(key[i]);
      }
      cout << endl;
    }
    return true;
  }
};

stopword_trie::value_t find( stopword_trie &trie, const char *search_str)
{
  int len_search_str = (int)strlen(search_str);
  return trie.find( search_str, len_search_str);
}

int main (int argc, const char * argv[])
{
  
  // CREATE STOPWORDS TRIE
  stopword_trie stop_words;
  
  
  const string STOPWORDS[] = { "a", "about", "above", "across", "after", "afterwards", "again", "against", "all", "almost", "alone", "along", "already", "also", "although", "always", "am", "among", "amongst", "amoungst", "amount", "an", "and", "another", "any", "anyhow", "anyone", "anything", "anyway", "anywhere", "are", "around", "as", "at", "back", "be", "became", "because", "become", "becomes", "becoming", "been", "before", "beforehand", "behind", "being", "below", "beside", "besides", "between", "beyond", "bill", "both", "bottom", "but", "by", "call", "can", "cannot", "cant", "co", "computer", "con", "could", "couldnt", "cry", "de", "describe", "detail", "do", "done", "down", "due", "during", "each", "eg", "eight", "either", "eleven", "else", "elsewhere", "empty", "enough", "etc", "even", "ever", "every", "everyone", "everything", "everywhere", "except", "few", "fifteen", "fify", "fill", "find", "fire", "first", "five", "for", "former", "formerly", "forty", "found", "four", "from", "front", "full", "further", "get", "give", "go", "had", "has", "hasnt", "have", "he", "hence", "her", "here", "hereafter", "hereby", "herein", "hereupon", "hers", "herself", "him", "himself", "his", "how", "however", "hundred", "i", "ie", "if", "in", "inc", "indeed", "interest", "into", "is", "it", "its", "itself", "keep", "last", "latter", "latterly", "least", "less", "ltd", "made", "many", "may", "me", "meanwhile", "might", "mill", "mine", "more", "moreover", "most", "mostly", "move", "much", "must", "my", "myself", "name", "namely", "neither", "never", "nevertheless", "next", "nine", "no", "nobody", "none", "noone", "nor", "not", "nothing", "now", "nowhere", "of", "off", "often", "on", "once", "one", "only", "onto", "or", "other", "others", "otherwise", "our", "ours", "ourselves", "out", "over", "own", "part", "per", "perhaps", "please", "put", "rather", "re", "same", "see", "seem", "seemed", "seeming", "seems", "serious", "several", "she", "should", "show", "side", "since", "sincere", "six", "sixty", "so", "some", "somehow", "someone", "something", "sometime", "sometimes", "somewhere", "still", "such", "system", "take", "ten", "than", "that", "the", "their", "them", "themselves", "then", "thence", "there", "thereafter", "thereby", "therefore", "therein", "thereupon", "these", "they", "thick", "thin", "third", "this", "those", "though", "three", "through", "throughout", "thru", "thus", "to", "together", "too", "top", "toward", "towards", "twelve", "twenty", "two", "un", "under", "until", "up", "upon", "us", "very", "via", "was", "we", "well", "were", "what", "whatever", "when", "whence", "whenever", "where", "whereafter", "whereas", "whereby", "wherein", "whereupon", "wherever", "whether", "which", "while", "whither", "who", "whoever", "whole", "whom", "whose", "why", "will", "with", "within", "without", "would", "yet", "you", "your", "yours", "yourself", "yourselves", "" };

	for (int i=0; STOPWORDS[i] != ""; i++ )
  { 
		stop_words.add(STOPWORDS[i], STOPWORDS[i].size(), i);
	}
  
  
  cout << "HW3" << endl;
  
  
  // CREATE DATA STRUCTURE
  return EXIT_SUCCESS;
  

  
  //while (!cin.eof())
    {
      // CHECK IF NOT A LETTER (isalpha)
    
      // CONVERT TO LOWERCASE (tolower)
    
      // READ WORD
      
      // COMPARE TO STOP WORDS TRIE // HASH FUNCTION?
      
      // POTENTIALLY USE STEMMER, TO MAKE WORDS MORE SIMPLE? //
      
      // ADD WORD TO DATA STRUCTURE
      // & INCREMENT COUNT OF WORD
      
      
    }
  
  // DATA STRUCTURE THOUGHTS
  //
  // Heap/Priority Queue might be good, would keep track of words with the highest occurance
  //
  //
  //
  //
  // 
  
  
  
  
  
  
  
  
  return EXIT_SUCCESS;
}

