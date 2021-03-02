#include <stdio.h>
#include <assert.h>
#include "checker.h"

bool ChecktemperatureInRange {
    bool temperatureflag = false;
    if(temperature < 0 || temperature > 45)
    {
        temperatureflag = true;
        printf("Temperature out of range!\n");
    }
    return temperatureflag;
}

bool ChecksocInRange{
    bool socFlag = false;
    if(soc < 20 || soc > 80) {
        {
            socFlag = true;
            printf("soc out of range!\n");
        }
        return socFlag;
    }

    bool CheckchargeRateInRange{
        bool ChargeRateflag = false;
        if(chargeRate > 0.8)
        {
            ChargeRateflag = true;
            printf("chargerate out of range!\n");
        }
        return ChargeRateflag;

    }
bool finalcheck{
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
