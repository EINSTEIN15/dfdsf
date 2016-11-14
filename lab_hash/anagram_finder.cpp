/**
 * @file anagram_finder.cpp
 * Implementation of the AnagramFinder class.
 *
 * @author Chase Geigle
 * @date Spring 2011
 * @date Summer 2012
 */

#include "anagram_finder.h"

using std::string;
using std::vector;
using std::ofstream;
using std::endl;

/**
 * Constructs an AnagramFinder based on a filename to read potential
 * anagrams from.
 *
 * @param ifilename The name of the file to read in.
 */
template <template <class K, class V> class Dict>
AnagramFinder<Dict>::AnagramFinder(const string& ifilename)
    : file(true), filename(ifilename)
{
    /* nothing */
}

/**
 * Constructs an AnagramFinder based on a set of strings instead of a
 * filename.
 *
 * @param istrings The set of strings to use for this finder.
 */
template <template <class K, class V> class Dict>
AnagramFinder<Dict>::AnagramFinder(const vector<string>& istrings)
    : file(false), strings(istrings)
{
    /* nothing */
}

/**
 * Determines if the given word is an anagram of the test word.
 *
 * @param word Word that is possibly an anagram.
 * @param test Word to check against.
 * @return A boolean value indicating whether word is an anagram of test.
 */
template <template <class K, class V> class Dict>
bool AnagramFinder<Dict>::checkWord(const string& word, const string& test)
{
    /**
     * @todo Implement this function! You should use the provided
     * templated hashtable class Dict.
     */
  
  if(word.length()!=test.length())
    {
      return false;

    }
  
int count1=0;
int count2=0; 
int count3=0; 
int count4=0; 
int count5=0; 
int count6=0; 
int count7=0; 
int count8=0; 
int count9=0; 
int count10=0; 
int count11=0; 
int count12=0; 
int count13=0; 
int count14=0; 
int count15=0; 
int count16=0; 
int count17=0;
int count18=0;
int count19=0;
int count20=0;
int count21=0;
int count22=0;
int count23=0;
int count24=0;
int count25=0;
int count26=0;

int count1b=0;
int count2b=0; 
int count3b=0; 
int count4b=0; 
int count5b=0; 
int count6b=0; 
int count7b=0; 
int count8b=0; 
int count9b=0; 
int count10b=0; 
int count11b=0; 
int count12b=0; 
int count13b=0; 
int count14b=0; 
int count15b=0; 
int count16b=0; 
int count17b=0;
int count18b=0;
int count19b=0;
int count20b=0;
int count21b=0;
int count22b=0;
int count23b=0;
int count24b=0;
int count25b=0;
int count26b=0;

char checkchar1='a';
char checkchar2='b';
char checkchar3='c';
char checkchar4='d';
char checkchar5='e';
char checkchar6='f';
char checkchar7='g';
char checkchar8='h';
char checkchar9='i';
char checkchar10='j';
char checkchar11='k';
char checkchar12='l';
char checkchar13='m';
char checkchar14='n';
char checkchar15='o';
char checkchar16='p';
char checkchar17='q';
char checkchar18='r';
char checkchar19='s';
char checkchar20='t';
char checkchar21='u';
char checkchar22='v';
char checkchar23='w';
char checkchar24='x';
char checkchar25='y';
char checkchar26='z';

for (unsigned long i = 0; i < word.size(); i++)
    {
        if (word[i] == checkchar1)
        {
            ++count1;
        }
	if(test[i]==checkchar1)
	  {
	    ++count1b;

	  }
    
 if (word[i] == checkchar2)
        {
            ++count2;
        }
	if(test[i]==checkchar2)
	  {
	    ++count2b;

	  }
 if (word[i] == checkchar3)
        {
            ++count3;
        }
	if(test[i]==checkchar3)
	  {
	    ++count3b;

	  }
 if (word[i] == checkchar4)
        {
            ++count4;
        }
	if(test[i]==checkchar4)
	  {
	    ++count4b;

	  }

 if (word[i] == checkchar5)
        {
            ++count5;
        }
	if(test[i]==checkchar5)
	  {
	    ++count5b;

	  }
 if (word[i] == checkchar6)
        {
            ++count6;
        }
	if(test[i]==checkchar6)
	  {
	    ++count6b;

	  }
 if (word[i] == checkchar7)
        {
	  ++count7;
        }
	if(test[i]==checkchar7)
	  {
	    ++count7b;

	  }
 if (word[i] == checkchar8)
        {
            ++count8;
        }
	if(test[i]==checkchar8)
	  {
	    ++count8b;

	  }
 if (word[i] == checkchar9)
        {
            ++count9;
        }
	if(test[i]==checkchar9)
	  {
	    ++count9b;

	  }
 if (word[i] == checkchar10)
        {
	  ++count10;
        }
	if(test[i]==checkchar10)
	  {
	    ++count10b;

	  }
 if (word[i] == checkchar11)
        {
	  ++count11;
        }
	if(test[i]==checkchar11)
	  {
	    ++count11b;

	  }
 if (word[i] == checkchar12)
        {
	  ++count12;
        }
	if(test[i]==checkchar12)
	  {
	    ++count12b;

	  }
 if (word[i] == checkchar13)
        {
	  ++count13;
        }
	if(test[i]==checkchar13)
	  {
	    ++count13b;

	  }
 if (word[i] == checkchar14)
        {
	  ++count14;
        }
	if(test[i]==checkchar14)
	  {
	    ++count14b;

	  }
 if (word[i] == checkchar15)
        {
	  ++count15;
        }
	if(test[i]==checkchar15)
	  {
	    ++count15b;

	  }
 if (word[i] == checkchar16)
        {
	  ++count16;
        }
	if(test[i]==checkchar16)
	  {
	    ++count16b;

	  }
 if (word[i] == checkchar17)
        {
	  ++count17;
        }
	if(test[i]==checkchar17)
	  {
	    ++count17b;

	  }
 if (word[i] == checkchar18)
        {
	  ++count18;
        }
	if(test[i]==checkchar18)
	  {
	    ++count18b;

	  }
 if (word[i] == checkchar19)
        {
	  ++count19;
        }
	if(test[i]==checkchar19)
	  {
	    ++count19b;

	  }
 if (word[i] == checkchar20)
        {
	  ++count20;
        }
	if(test[i]==checkchar20)
	  {
	    ++count20b;

	  }
 if (word[i] == checkchar21)
        {
            ++count21;
        }
	if(test[i]==checkchar21)
	  {
	    ++count21b;

	  }
 if (word[i] == checkchar22)
        {
            ++count22;
        }
	if(test[i]==checkchar22)
	  {
	    ++count22b;

	  }
	if (word[i] == checkchar23)
        {
            ++count23;
        }
	if(test[i]==checkchar23)
	  {
	    ++count23b;

	  }
	  if (word[i] == checkchar24)
        {
            ++count24;
        }
	  if(test[i]==checkchar24)
	  {
	    ++count24b;

	  }
	  if (word[i] == checkchar25)
        {
            ++count25;
        }
	  if(test[i]==checkchar25)
	  {
	    ++count25b;

	  }
	  if (word[i] == checkchar26)
        {
            ++count26;
        }
	  if(test[i]==checkchar26)
	  {
	    ++count26b;

	  }
    }
	  if(
	     count1==count1b&&count2==count2b&&count3==count3b&&count4==count4b&&count5==count5b&&count6==count6b&&count7==count7b&&count8==count8b&&count9==count9b&&count10==count10b&&count11==count11b&&count12==count12b&&count13==count13b&&count14==count14b&&count15==count15b&&count16==count16b&&count17==count17b&&count18==count18b&&count19==count19b&&count20==count20b&&count21==count21b&&count22==count22b&&count23==count23b&&count24==count24b&&count25==count25b&&count26==count26b)
	    {
	      return true;

	    }

	  else
	    { 
	       return false;

	    }
}





  //  (void) word; // prevent warnings... When you implement this function, remove this line.
  // (void) test; // prevent warnings... When you implement this function, remove this line.

  


/**
 * Retrieves a set of words that are anagrams of a given word.
 *
 * @param word The word we wish to find anagrams of inside the finder.
 */
template <template <class K, class V> class Dict>
vector<string> AnagramFinder<Dict>::getAnagrams(const string& word)
{
    // set up the return vector
    vector<string> ret;

    if (file) {
        TextFile infile(filename);
        string line;
        vector<string> tests;
        while (infile.good()) {
            string test = infile.getNextWord();
            if (checkWord(word, test))
                ret.push_back(test);
        }
    } else {
        for (size_t i = 0; i < strings.size(); i++) {
            if (checkWord(word, strings[i]))
                ret.push_back(strings[i]);
        }
    }
    return ret;
}

/**
 * Retrieves a set of anagrams in the finder of a given words, but writes
 * them out to a file instead of returning a vector.
 *
 * @param word The word we wish to find anagrams of inside the finder.
 * @param output_file The name of the file we want to write to.
 */
template <template <class K, class V> class Dict>
void AnagramFinder<Dict>::writeAnagrams(const string& word,
                                        const string& output_file)
{
    vector<string> anagrams = getAnagrams(word);
    ofstream outfile(output_file.c_str());
    if (outfile.is_open()) {
        for (size_t i = 0; i < anagrams.size(); i++)
            outfile << anagrams[i] << endl;
    }
    outfile.close();
}
