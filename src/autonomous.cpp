#include "main.h"

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
 #define LEFT_WHEELS_PORT 1
 #define RIGHT_WHEELS_PORT 10
 #define MOTOR_MAX_SPEED 50 // The motor has the 36 Gearset

 void autonomous() {
   pros::Motor left_wheels (LEFT_WHEELS_PORT, MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
   pros::Motor right_wheels (RIGHT_WHEELS_PORT, MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES); // This reverses the motor

   std::cout << "Moving autonomous \n";       // Show to the terminal Debug info
   std::cout << "Motor Position: " << left_wheels.get_position() << "Right: " << right_wheels.get_position() << "\n";

   right_wheels.move_relative(1000, MOTOR_MAX_SPEED);
   left_wheels.move_relative(1000, MOTOR_MAX_SPEED);
   pros::delay(4000);
   std::cout << "Motor Position: " << left_wheels.get_position() << "Right: " << right_wheels.get_position() << "\n";

   left_wheels.move_relative(360, MOTOR_MAX_SPEED);
 }
