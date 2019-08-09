#include<string.h>
#include <iostream>
#include<string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

string weapons[3]={"sword","bomb","arrow"};
  int samcreate[5]={3,4,5,6,7};
class samurai
{

    public:
       samurai(int id,double l)
       :sam_id(id)
       ,life(l)
       {
           cout<<"samurai(double)"<<endl;
       }

       int getID()
       {
           return sam_id;
       }
       int getLife()
       {
           return life;
       }
    

    private:
        int sam_id;
        double life;
} ;
//🐲武士 有一件武器  n%3  和士气 
class dragon:public samurai
{
    public:
            dragon(int id,int l,int w,double m)
            :samurai(id,l)
            ,weapon(w)
            ,morale(m)
            {
                cout<<"dragon(int ,int ,double)"<<endl;
            }
            int getWeapon()
            {
                return weapon;
            }
            double getMorale()
            {
                return morale;
            }
    private: int weapon;
             double morale;
};
//腻腻加 武士 两件武器 
class ninja:public samurai
{
    public :
            ninja(int id,int l,int w1,int w2)
            :samurai(id,l)
            ,weapon1(w1)
            ,weapon2(w2)
            {
                cout<<"ninja(int ,int ,int )"<<endl;

            }
            int getWeapon1()
            {
                return weapon1;
            }
            int getWeapon2()
            {
                return weapon2;
            }
    private:int weapon1;
            int weapon2;
};
//冰人武士  一件武器
class iceman:public samurai
{
    public :
    iceman(int id,int l,int w)
    :samurai(id,l)
    ,weapon(w)
    {
        cout<<"iceman(int ,int )"<<endl;
    }
    int getWeapon()
    {
        return weapon;
    }
    private: int weapon;
};
//蓝魔武士  忠诚度

class lion:public samurai
{
    public:
    lion(int id,int l, int lo)
    :samurai(id,l)
    ,loyal(lo)
    {
        cout<<"lion(int ,int )"<<endl;
    }
    int getLoyal()
    {
        return loyal;
    }
    private:int loyal;
};

//🐺武士 没特点
class wolf:public samurai
{
    public:
          wolf(int id,int l)
          :samurai(id,l)
          {
               cout<<"wolf(int ,int)"<<endl;
          }
};


class  headquarters
{
    public:
            headquarters(string n,int h,int s)
            :name(n)
            ,headlife(h)
            ,sum(s)
            {
                cout<<"headquarters(string ,int)"<<endl;

            }
            string getName()
            {
                return name;
            }
            int getLife()
            {
                return headlife;
            }
            int getSum()
            {
                return sum;
            }
            void addsamuri()
            {
                sum++;
            }
            void subheadlife(int sub)
            {
                headlife-=sub;
            }

            void dragon_push(dragon & _dragon)
            {
                dragon_vector.push_back(_dragon);
                cout<<name<< "  dragon  "<< _dragon.getID()<<"  born with strength "<<_dragon.getLife()<<","
                    <<dragon_vector.size()<<" dragon in "<<name<<"  headquarter . it has a  "<<weapons[_dragon.getWeapon()]
                    <<"  ,and its morale is "<<_dragon.getMorale()
                    <<endl;
    
            }
              void iceman_push(iceman & _iceman)
            {
                iceman_vector.push_back(_iceman);
                 cout<<name<< "  iceman  "<< _iceman.getID()<<" born with strength "<<_iceman.getLife()<<","
                    <<iceman_vector.size()<<" iceman in "<<name<<" headquarter . it has a "<<weapons[_iceman.getWeapon()]
                    <<endl;

            }
             void ninja_push(ninja & _ninja)
            {
                ninja_vector.push_back(_ninja);
                 cout<<name<< " ninja "<< _ninja.getID()<<" born with strength  "<<_ninja.getLife()<<","
                    <<ninja_vector.size()<<" ninja in "<<name<<" headquarter . it has a "<<weapons[_ninja.getWeapon1()]
                    <<" and it has a "<<weapons[_ninja.getWeapon2()]
                    <<endl;

            }
              void lion_push(lion & _lion)
            {
                lion_vector.push_back(_lion);
                 cout<<name<< " lion "<< _lion.getID()<<" born with strength "<<_lion.getLife()<<","
                    <<lion_vector.size()<<" lion in "<<name<<" headquarter . it's loyalty is "<<_lion.getLoyal()
                    <<endl;

            }
             void wolf_push(wolf & _wolf)
            {
                wolf_vector.push_back(_wolf);
                  cout<<name<< " wolf "<< _wolf.getID()<<" born with strength "<<_wolf.getLife()<<","
                    <<wolf_vector.size()<<" wolf in "<<name<<" headquarter "
                    <<endl;

            }
         

    private:
            vector<iceman> iceman_vector;
            vector<dragon> dragon_vector;
            vector<ninja>  ninja_vector;
            vector<wolf> wolf_vector;
            vector<lion> lion_vector;
            string name;
            int headlife;
            int sum;



};

void create(headquarters& head,int i)
{
    int s=head.getSum();
   if(i==0)
   {
        cout << "----------------------make ------dragon" << endl; 
        dragon _dragon (s,samcreate[i],head.getLife()%3,(double)head.getLife()/(double)samcreate[i]);
        head.dragon_push(_dragon);
        head.addsamuri();
        
        

   }
   else if(i==1)
   {
        cout << "----------------------make --------ninja" << endl;
        ninja _ninja(s,samcreate[i],head.getLife()%3,(head.getLife()+1)%3);
        head.ninja_push(_ninja);
        head.addsamuri();

   }
   else if(i==2)
   {

      cout << "-----------------------make---------iceman" << endl;
      iceman _iceman(s,samcreate[i],head.getLife()%3);
      head.iceman_push(_iceman);
      head.addsamuri();

   }
   else if(i==3)
   {
         cout << "-------------------make----------lion" << endl;
      lion _lion(s,samcreate[i],head.getLife());
      head.lion_push(_lion);
      head.addsamuri();

   }
   else
   {
        cout << "----------------make----------wolf" << endl;
         wolf _wolf(s,samcreate[i]);
         head.wolf_push(_wolf);
        head.addsamuri();
   }

     

  
//    int s=head.getSum();
//    switch(i)
//    {
//    case 0 :
//       cout << "dragon" << endl; 
//        dragon dragon1 (1,1,1,2.4);
//        dragon _dragon (s,samcreate[i],head.getLife()%3,head.getLife()/samcreate[i]);
//        head.addsamuri();
       
//       break;
//    case 1 :
//       cout << "ninja" << endl;
//     //   ninja _ninja(s,samcreate[i],head.getLife()%3,(head.getLife+1)%3);
//     //   head.addsamuri();
//       break;
//    case 2 :
//       cout << "iceman" << endl;
//     //   iceman _iceman(s,samcreate[i],head.getLife()%3);
//     //   head.addsamuri();
//       break;
//    case 3 :
//       cout << "lion" << endl;
//     //   lion _lion(s,samcreate[i],head.getLife());
//     //   head.addsamuri();
//       break;
//     case 4 :
//       cout << "wolf" << endl;
//     //   wolf _wolf(s,samcreate[i]);
//     //   head.addsamuri();
//       break;
//    default :
//       cout << "无效输入" << endl;
//    }
 

}

int main()
{

    headquarters red("red",20,0);

      cout<<red.getLife()<<endl;
    
      int headlife=red.getLife();
      int i=0;
      int temp=0;
      while(red.getLife())
      {
          cout<<red.getLife()<<endl;
          if(temp<5){
              if(samcreate[i]<red.getLife())//如果可以制造
             {
                 create(red,i);
                 red.subheadlife(samcreate[i]);    
                 cout<<"sub-------"<<red.getLife()<<endl;    
                 i=(i+1)%5;

            }
            else
            {
                  temp++;
                  i=(i+1)%5;
            }
            }
         else
         { 
                 break;
         }
          
          
      }
       
    
    //   vector<samurai> samurai_vector; 
    //   samurai_vector.push_back(i1);
    //    samurai_vector.push_back(w1);

    // vector<samurai>::iterator _begin= (&samurai_vector)->begin();
    // vector<samurai>::iterator _end= (&samurai_vector)->end();
    // cout<<"-----------============="<<(&samurai_vector)->size()<<endl;
    // ++_begin;
    
    // while(_begin!=_end){
    //      cout<<_begin->sam_id<<endl;
    //     ++_begin;
    // }




    return 0;

}