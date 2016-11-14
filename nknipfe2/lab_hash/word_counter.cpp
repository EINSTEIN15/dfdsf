/**
 * @file word_counter.cpp
 * Implementation of the WordFreq class.
 *
 * @author Chase Geigle
 * @date Spring 2011
 * @date Spring 2012
 */

using std::vector;
using std::pair;
using std::string;
using std::ifstream;
using std::istringstream;
using std::cout;
using std::endl;

template <template <class K, class V> class Htable>
WordFreq<Htable>::WordFreq(const string& infile)
    : filename(infile)
{
    /* nothing */
}

template <template <class K, class V> class Htable>
vector<pair<string, int>> WordFreq<Htable>::getWords(int threshold) const
{
    TextFile infile(filename);
    Htable<string,int>table1(256);
    while(infile.good())
      {
      string word=infile.getNextWord();
      
	
	  table1[word]++;

	

      }
    vector<pair<string, int>> ret;
    /**
     * @todo Implement this function.
     * @see char_counter.cpp if you're having trouble.
     */
    typename Htable<string,int>:: iterator it;
for (it = table1.begin(); it != table1.end(); it++) 
  {
        if (it->second >= threshold)
            ret.push_back(*it);
    }
    return ret;






    // (void) threshold; // prevent warnings... When you implement this function, remove this line.

    //return ret;
}
