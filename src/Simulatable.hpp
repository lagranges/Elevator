#ifndef SIMULATABLE_INCLUDED
#define SIMULATABLE_INCLUDED

class Simulatable
{
    public:
        Simulatable();
        virtual ~Simulatable();
        virtual void run() = 0 ;
        virtual void draw() = 0;
        virtual void reset() = 0;

};

#endif // SIMULATABLE_INCLUDED
