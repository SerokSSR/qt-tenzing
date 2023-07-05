#ifndef POKEMON_H
#define POKEMON_H

#endif // POKEMON_H
#include<QWidget>

class skill{
protected:
    int pp,pp_now;
    int pow;
    int prior;
    QString name,type;
public:
    skill(QString name0="",int pp0=0,int pow0=0,int prior0=0,QString type0=""):pp(pp0),pp_now(pp0),pow(pow0),name(name0),prior(prior0),type(type0){}
    int get_pp(){return pp_now;}
    int get_pp_max(){return pp;}
    int get_prior(){return prior;}
    int get_pow(){return pow;}
    void use_pp(){pp_now--;  }
    QString& get_name(){return name;}
    QString& get_type(){return type;}
};

class pokemon{
protected:
    int hp,atk,spd,def,sa,sd;
    int level[6];
    QString name;
public:
    int hp_now,suc,fir;
    friend skill;
    skill skl[4];
    pokemon(QString name0,int hp0,int atk0,int spd0,int def0,int sa0,int sd0,skill skill0,skill skill1,skill skill2,skill skill3):hp(hp0),atk(atk0),spd(spd0),def(def0),sa(sa0),sd(sd0){
        name=name0;
        skl[0]=skill0;
        skl[1]=skill1;
        skl[2]=skill2;
        skl[3]=skill3;
        hp_now=hp;
        suc=0,fir=1;
    }
    int get_pp(int idx){ return skl[idx].get_pp();}
    int get_pp_max(int idx){return skl[idx].get_pp_max();}
    int get_hp_now(){return hp_now;}
    int get_hp(){return hp;}
    int get_atk(){return atk;}
    int get_def(){return def;}
    QString get_name(){return name;}
    bool cmpspd(pokemon& p){
        return spd>p.spd;
    }
    friend bool judge_prior(pokemon* poke1,pokemon* poke2,skill& skl1, skill& skl2){
        if(skl1.get_name()=="突袭"&&skl2.get_name()!="守住") return 1;
        if(skl2.get_name()=="突袭"&&skl1.get_name()!="守住") return 0;
        if(skl1.get_prior()>skl2.get_prior()) return 1;
        if(skl2.get_prior()>skl1.get_prior()) return 0;
        if(poke1->spd>poke2->spd) return 1;
        if(poke2->spd>poke1->spd) return 0;
        return rand()%2;
    }
};

class SuckerPunch:public skill{
public:
    SuckerPunch():skill("突袭",5,70,1,"物理"){}
};

class IcicleCrash:public skill{
public:
    IcicleCrash():skill("冰柱坠击",10,85,1,"物理"){}
};

class SacredSword:public skill{
public:
    SacredSword():skill("圣剑",15,90,1,"物理"){}
};

class Protect:public skill{
public:
    Protect():skill("守住",10,0,4,"变化"){}
    static int pro[6];
};

class Wildcharge:public skill{
public:
    Wildcharge():skill("疯狂伏特",15,90,1,"物理"){}
};

class Drainpunch:public skill{
public:
    Drainpunch():skill("吸取拳",10,75,1,"物理"){}
};

class ThunderPunch:public skill{
public:
    ThunderPunch():skill("雷电拳",15,75,1,"物理"){}
};

class chienpao:public pokemon{
public:
    chienpao():pokemon("古剑豹",270,220,247,148,166,121,SuckerPunch(),IcicleCrash(),SacredSword(),Protect()){}
};

class ironhands:public pokemon{
public:
    ironhands():pokemon("铁臂膀",318,256,94,198,94,126,Wildcharge(),Drainpunch(),ThunderPunch(),Protect()){}
};
