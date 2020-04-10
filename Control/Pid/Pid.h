#include "globals.h"

#ifndef PID_H
#define PID_H

class Pid{

    public:

        /*
        ===============================
        Class-specific global variables
        ===============================
        */

        float kP; float kI; float kD;
        float minOut; float maxOut;
        float integrator; float diff; //IRM Diff stands for differentiation
        float error;
        float setPoint;




        //IRM Constructor and destructor
        Pid(float p, float i, float d, float minO, float maxO);
        ~Pid();



        /*
        ===========================================
        IRM Class-specific public method prototypes
        ===========================================
        */

        //Variables initialization. Set initial values to class global variables
        void  pidInit(float p, float i, float d, float minO, float maxO);

        //Establish set-point value
        void  pidSetPoint(float sp);

        //Feed PID with current sample and fetch next computed output value
        float pidUpdate(float currentValue);

    private:

        //IRM encapsulated method prototypes
        void __resetIDvalues();
        void __accumulateIntegration(float e);


        //IRM private setters
        void __setErrorValue(float e);
        void __setIntegratorValue(float i);
        void __setDiffValue(float d);
        

        //IRM private getters
        float __getErrorvalue();
        float __getKp();
        float __getKi();
        float __getKd();
        float __getMinOut();
        float __getMaxOut();

        float __getIntegratorValue();
        float __getDiffValue();

};

#endif
