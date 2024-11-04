#include <gtest/gtest.h>
#include "typewise-alert.h"

// Test for inferBreach function
TEST(TypeWiseAlertTestSuite, InfersBreachAccordingToLimits) {
    EXPECT_EQ(inferBreach(12, 20, 30), TOO_LOW);
    EXPECT_EQ(inferBreach(25, 20, 30), NORMAL);
    EXPECT_EQ(inferBreach(35, 20, 30), TOO_HIGH);
}

// Test for classifyTemperatureBreach function
TEST(TypeWiseAlertTestSuite, ClassifiesTemperatureBreach) {
    EXPECT_EQ(classifyTemperatureBreach(PASSIVE_COOLING, 20), NORMAL);
    EXPECT_EQ(classifyTemperatureBreach(PASSIVE_COOLING, 40), TOO_HIGH);
    EXPECT_EQ(classifyTemperatureBreach(HI_ACTIVE_COOLING, 40), NORMAL);
    EXPECT_EQ(classifyTemperatureBreach(HI_ACTIVE_COOLING, 50), TOO_HIGH);
    EXPECT_EQ(classifyTemperatureBreach(MED_ACTIVE_COOLING, 35), NORMAL);
    EXPECT_EQ(classifyTemperatureBreach(MED_ACTIVE_COOLING, 45), TOO_HIGH);
}

// Test for checkAndAlert function
TEST(TypeWiseAlertTestSuite, ChecksAndAlerts) {
    BatteryCharacter batteryChar;
    batteryChar.coolingType = PASSIVE_COOLING;
    checkAndAlert(TO_CONTROLLER, batteryChar, 40);
    checkAndAlert(TO_EMAIL, batteryChar, 40);
}

// Test for sendToController function
TEST(TypeWiseAlertTestSuite, SendsToController) {
    sendToController(TOO_HIGH);
}

// Test for sendToEmail function
TEST(TypeWiseAlertTestSuite, SendsToEmail) {
    sendToEmail(TOO_LOW);
    sendToEmail(TOO_HIGH);
    sendToEmail(NORMAL);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
