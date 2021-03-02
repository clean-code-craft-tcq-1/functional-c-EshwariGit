#include <stdio.h>
#include <assert.h>
#include "checker.h"
bool socFlag = false;
bool temperatureflag = false;
bool ChargeRateflag = false;
bool ChecktemperatureInRange(float temperature) {
   
    if(temperature < 0 || temperature > 45)
    {
        temperatureflag = true;
        printf("Temperature out of range!\n");
    }
    return temperatureflag;
}

bool ChecksocInRange(float soc){
   
    if(soc < 20 || soc > 80) {
        {
            socFlag = true;
            printf("soc out of range!\n");
        }
        return socFlag;
    }

    bool CheckchargeRateInRange(float chargeRate){
      
        if(chargeRate > 0.8)
        {
            ChargeRateflag = true;
            printf("chargerate out of range!\n");
        }
        return ChargeRateflag;

    }
int finalcheck{
    if((temperatureflag || socFlag || ChargeRateflag == true) )
{
    return 0;

}
else
{
    return 1;
}
    
}
int batteryIsOk(float temperature, float soc, float chargeRate) {

finalcheck();
    }

    int main() {
        assert(batteryIsOk(25, 70, 0.7));
        assert(!batteryIsOk(50, 85, 0));
    }
