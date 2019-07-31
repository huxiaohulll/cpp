#include "tinyxml2.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <ctime>
using std::cout;
using std::endl;
using std::vector; 

using namespace tinyxml2;
using namespace std;


class xmlinfo{
    public:
        ~xmlinfo(){
            cout<<"~information"<<endl;
        }
    public:
        string title;
        string link;
        string description;
  //      string  content;
    
};



void dump(vector <xmlinfo> * _vecotr){

    std::ofstream _ostream("pagelib.dat",std::ios::app);

    vector<xmlinfo>::iterator _begin= _vecotr->begin();
    vector<xmlinfo>::iterator _end= _vecotr->end();
    cout<<"-----------============="<<_vecotr->size()<<endl;
    ++_begin;
    int i=0;
    while(_begin!=_end){
        _ostream<<"<doc>"<<endl;
        _ostream<<"<docid>"<<i<<"</docid>"<<endl;
        _ostream<<"<title>"<<_begin->title<<"</title>"<<endl;
        _ostream<<"<link>"<<_begin->link<<"</link>"<<endl;
        _ostream<<"<description>"<<_begin->description<<"</description>"<<endl;
//      _ostream<<"<content>"<<_begin->content<<"</content>"<<endl;
        _ostream<<"</doc>"<<endl;
        ++_begin;
    }
}


int main(void)
{
    XMLDocument doc;
    doc.LoadFile("coolshell.xml");
    XMLElement*  root = doc.RootElement();
    XMLElement* channel = root->FirstChildElement("channel");
    if(NULL==channel){
        cout<<"get first chile element error "<<endl;
        exit(0);
    }
     XMLElement* item = channel->FirstChildElement("item");
    if(NULL==item){
        cout<<"get first chile element error "<<endl;
        exit(0);
    }
    XMLElement * title = item->FirstChildElement("title");
    cout<<title->GetText()<<endl;
    cout<<title->Name()<<endl;
     XMLElement * link = item->FirstChildElement("link");
    cout<<link->GetText()<<endl;
    cout<<link->Name()<<endl;
     XMLElement * description = item->FirstChildElement("description");
    cout<<description->GetText()<<endl;
    cout<<description->Name()<<endl;

     xmlinfo temp;
     temp.title=title->GetText();
     temp.link=link->GetText();
     temp.description=description->GetText();
     cout<<"----------"<<temp.title<<endl;
     vector<xmlinfo> information_vector;  //定义一个vector存放信息
     information_vector.push_back(temp);
    

    item = item->NextSiblingElement();
    item=item->NextSiblingElement("item");
    while(item)
    {
         title = item->FirstChildElement("title");
         cout<<title->GetText()<<endl;
         cout<<title->Name()<<endl;
         link = item->FirstChildElement("link");
         cout<<link->GetText()<<endl;
         cout<<link->Name()<<endl;
         description = item->FirstChildElement("description");
         cout<<description->GetText()<<endl;
         cout<<description->Name()<<endl;

         /*
             放入vector
          */
          xmlinfo temp;
          temp.title=title->GetText();
          temp.link=link->GetText();
          temp.description=description->GetText();
          cout<<"----------"<<temp.title<<endl;
     
          information_vector.push_back(temp);

          item=item->NextSiblingElement("item");

    }
  
     dump(&information_vector);
        
    
    
  

    return 0;
}