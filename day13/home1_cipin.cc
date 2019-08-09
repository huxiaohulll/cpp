#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<map>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;
using std::map;
using std::pair;


template<class Container>
void display(const Container &c)
{

    std::ofstream _ostream("bible.txt",std::ios::app);


 
    typename Container::const_iterator cit=c.begin();
    for(;cit!=c.end();cit++)
    {
      
           _ostream<<cit->first<<"---->"<<cit->second<<endl;
    }
}


void dealstring(string &s)
{
       
        for(int i=0;i<s.size();i++)
       {
      
        if(isalpha(s[i])||s[i]=='-')
        {
          
            s[i]=tolower(s[i]);
        
         
        }
        else
        {
            
               s.erase(i,1);
          
               i--;
            
        }
        
    }

}
void test0()
{
    map<string,int> words;
    ifstream ifs;
    ifs.open("The_Holy_Bible.txt");
    if(!ifs.good())
    {
        cout<<"ifstream open file error"<<endl;
        return ;
    }
    string word;
    while(ifs>>word)
    {
       
        dealstring(word);
        if(word.size()!=0)
        ++words[word];
        
    }
    display(words);
  
    

}
int main(void)
{
    test0();

    return 0;
}

