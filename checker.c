#include <stdio.h>
#include <assert.h>
#include "checker.h"


static bms_Status BMS_parameters_s = {
        false,
        false,
        false,
        false
}

bool ChecktemperatureInRange(float temperature) {

    if(temperature < 0 || temperature > 45)
    {
        temperatureflag = true;
        printf("Temperature out of range!\n");
        finalcheck(true);
    }
    return temperatureflag;
}

bool ChecksocInRange(float soc){

    if(soc < 20 || soc > 80) {
        {
            socFlag = true;
            printf("soc out of range!\n");
            finalcheck(true);
        }
        return socFlag;
    }
}

    bool CheckchargeRateInRange(float chargeRate){

        if(chargeRate > 0.8)
        {
            ChargeRateflag = true;
            printf("chargerate out of range!\n");
            finalcheck(true);
        }
        return ChargeRateflag;

    }

void finalcheck(bool bms_Status){

    BMS_parameters_s.bms_Status = true;

}
int batteryIsOk(float temperature, float soc, float chargeRate) {
    BMS_parameters_s.socFlag = ChecksocInRange(soc);
    BMS_parameters_s.temperatureflag =ChecktemperatureInRange(temperature);
    BMS_parameters_s.ChargeRateflag = CheckchargeRateInRange(chargeRate);

    if( true == BMS_parameters_s.bms_Status)
     {
         return 0;
     }
     else
     {
         return 1;
     }
    }

    int main() {
        assert(batteryIsOk(25, 70, 0.7));
        assert(!batteryIsOk(50, 85, 0));
    }
