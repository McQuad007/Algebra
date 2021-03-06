#include "monomy.h"
class polinomy
{
    public:
        polinomy();
        void make(string tip_num);
        void getMonomy(double,string,double);
        void oper();
        void der(string var);
        void integ(string var);
        void print();
        void eraseMonomy(monomy &a);
        polinomy pow_(double a);
        polinomy &operator=(const polinomy &);
        polinomy operator*(const polinomy &);
        polinomy operator/(const polinomy &);
        polinomy operator+(const polinomy &);
        polinomy operator-(const polinomy &);
    private:
        vector<monomy> alg;

};

polinomy::polinomy()
{

}

void polinomy::make(string tip_num)
{
    char x='z';
    while(x!='c')
    {
        system(_cls);
        cout<<"Crear un monomio?:(x=si||c=no)_:";
        cin>>x;
        if(x=='x')
        {

            monomy a;
            a.make(tip_num);
            alg.push_back(a);
        }
    }
    for(int i=0;i<alg.size();i++)
    {
        alg[i].oper();
    }
    system(_cls);
}

void polinomy::oper()
{
    for(int i=0;i<alg.size()-1;i++)
    {
        for(int j=i+1;j<alg.size();j++)
        {

                if(alg[i]==alg[j])
                {
                    alg[i].num=alg[i].num+alg[j].num;
                    alg.erase(alg.begin()+j);
                    j--;
                }
        }
    }
}



void polinomy::print()
{

    for(int i=0;i<alg.size();i++)
    {
        if(alg[i].num>0&&i!=0)cout<<"+";
        alg[i].print();
    }
}

void polinomy::der(string var)
{
    for(int i=0;i<alg.size();i++)
    {
        alg[i].der(var);
    }
    if(var!="c")
    {
        monomy z;
        z.get(1,"c",1);
        eraseMonomy(z);
    }

}

void polinomy::integ(string var)
{
    for(int i=0;i<alg.size();i++)
    {
        alg[i].integ(var);
    }
    if(alg.size()!=0)
    {
        monomy c;
        c.get(1,"c",1);
        alg.push_back(c);
    }
    oper();

}

void polinomy::getMonomy(double num,string var,double exp)
{
    monomy j;
    j.get(num,var,exp);
    alg.push_back(j);
    oper();
}

polinomy &polinomy::operator=(const polinomy &a)
{
    alg=a.alg;
    return *this;
}

polinomy polinomy::operator*(const polinomy &a)
{
    polinomy z;

    for(int i=0;i<alg.size();i++)
    {

        for(int j=0;j<a.alg.size();j++)
        {
            monomy m;
            m=alg[i]*a.alg[j];
            z.alg.push_back(m);
        }
    }
    z.oper();
    return z;
}

void polinomy::eraseMonomy(monomy &a)
{

    for(int i=0;i<alg.size();i++)
    {
        if(a==alg[i])
        {
            alg.erase(alg.begin()+i);
        }
    }
}

polinomy polinomy::pow_(double a)
{
    polinomy b;
    for(int i=0;i<alg.size();i++)
    {
        monomy x;
        x=alg[i].pow_(a);
        b.alg.push_back(x);
    }
    return b;
}



polinomy polinomy::operator/(const polinomy &a)
{
    polinomy b, r;
    b=a;
    r=*this*b.pow_(-1);
    r.oper();
    return r;
}

polinomy polinomy::operator+(const polinomy &a)
{
    polinomy r;
    r=*this;
    for(int i=0;i<a.alg.size();i++)
    {
        r.alg.push_back(a.alg[i]);
    }
    r.oper();
    return r;
}

polinomy polinomy::operator-(const polinomy &a)
{
    polinomy m, r;
    m=a;
    for(int i=0;i<m.alg.size();i++)
    {
        m.alg[i].num=m.alg[i].num*-1;
    }
    r=*this+m;
    r.oper();
    return r;
}
