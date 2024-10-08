#include "Robot.h"
#include <fmt/core.h>

void Robot::RobotInit() {
  // Initialize Xbox controllers
  xboxController1 = std::make_unique<frc::XboxController>(0);
  xboxController2 = std::make_unique<frc::XboxController>(1);

  // Initialize motor controllers with CAN ID
  m_CAN8 = std::make_unique<WPI_VictorSPX>(8);
  m_CAN3 = std::make_unique<WPI_VictorSPX>(3);
  m_CAN1 = std::make_unique<WPI_VictorSPX>(1);
  m_CAN2 = std::make_unique<WPI_VictorSPX>(2);
  
  // Invert the drive motors on the right side
  m_rightMotor.SetInverted(true);

  // send camera data to smartdashboard and FRC control panel
  frc::CameraServer::StartAutomaticCapture();
  
  // put the 4 autos onto smartdashboard defined in include.h
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom1, kAutoNameCustom1);
  m_chooser.AddOption(kAutoNameCustom2, kAutoNameCustom2);
  m_chooser.AddOption(kAutoNameCustom3, kAutoNameCustom3);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
}


void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {
  // start timer
  timer.Reset();
  timer.Start();

  // get chosen automonous from smartdashboard and initialize it as m_autoSelected
  m_autoSelected = m_chooser.GetSelected();
}


void Robot::AutonomousPeriodic() {
  /* 
    if (timer.Get() <= 2_s) {}
  */

  
// go through each auto comparing it to m_autoSelected
if (m_autoSelected == "Default Automonous") {
  
} else if (m_autoSelected == "Auto 1") {

} else if (m_autoSelected == "Auto 2") {

} else {
    m_robotDrive.ArcadeDrive(0.0,0.0);
}
}

void Robot::TeleopPeriodic() {

   // --------------------------------------------------------------------------------------------------
   // --------------------------------------------------------------------------------------------------
   // --------------------------------------------------------------------------------------------------
  
  // Get button status of controller 1
  bool C1aButtonPressed = xboxController1->GetAButton();
  bool C1yButtonPressed = xboxController1->GetYButton();
  bool C1xButtonPressed = xboxController1->GetXButton();
  bool C1bButtonPressed = xboxController1->GetBButton();

  // get back and start button status of controller 1
  bool C1backButtonPressed = xboxController1->GetBackButton();
  bool C1startButtonPressed = xboxController1->GetStartButton();

  // get triggers for controller 1
  bool C1leftTrigger = xboxController1->GetLeftTriggerAxis();
  bool C1rightTrigger = xboxController1->GetRightTriggerAxis();

  // Get bumper values of controller 1
  bool C1rightBumper = xboxController1->GetRightBumper();
  bool C1leftBumper = xboxController1->GetLeftBumper();

  
  // --------------------------------------------------------------------------------------------------

  
  // Get bumper values of controller 2
  bool C2rightBumper = xboxController2->GetRightBumper();
  bool C2leftBumper = xboxController2->GetLeftBumper();
  
  // Get button status of controller 2
  bool C2aButtonPressed = xboxController2->GetAButton();
  bool C2yButtonPressed = xboxController2->GetYButton();
  bool C2xButtonPressed = xboxController2->GetXButton();
  bool C2bButtonPressed = xboxController2->GetBButton();

  // get back and start button status of controller 2
  bool C2backButtonPressed = xboxController2->GetBackButton();
  bool C2startButtonPressed = xboxController2->GetStartButton();

  // get triggers for controller 2
  bool C2leftTrigger = xboxController2->GetLeftTriggerAxis();
  bool C2rightTrigger = xboxController2->GetRightTriggerAxis();


   // --------------------------------------------------------------------------------------------------
   // --------------------------------------------------------------------------------------------------
   // --------------------------------------------------------------------------------------------------

  
  // drive using controller 2
  m_robotDrive.ArcadeDrive(speed*m_driverController2.GetLeftY(), -speed*m_driverController2.GetRightX());


   // --------------------------------------------------------------------------------------------------
   // --------------------------------------------------------------------------------------------------
   // --------------------------------------------------------------------------------------------------

  
  

// change speeds with controller 2's triggers
  if (C2leftTrigger) {
    speed=slow;
  }
  else if (C2rightTrigger)  {
    speed = fast;
  }
  else {
    speed = reg;
  }

} // this is the end of TeleOperatedPeriodic() {}


int main() {
    return frc::StartRobot<Robot>();
}
