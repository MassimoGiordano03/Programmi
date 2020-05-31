/**
   
   firmware.ino

-----------------------------------------------------

   Copyright 2018 Emanuele Giacomini
   
   Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at
   
       http://www.apache.org/licenses/LICENSE-2.0
   
   Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an 
   "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and limitations under the License.
**/

#include "phoenix_params.h"
#include "phoenix_globals.h"
#include "phoenix_joints.h"
#include "phoenix_drive.h"
#include "phoenix_line_internal.h"
#include "phoenix_line.h"
#include "phoenix_imu.h"
#include "phoenix_timer.h"
#include "phoenix_encoders.h"

struct Timer* test1;

void setup() {
  cli();
  Serial.begin(9600);
  Serial.println("Serial initialized...");

  Encoder_init();
  for(int i=0;i<NUM_JOINTS;++i) {
    PhoenixJoint_init(&joints[i]);
  }
  Serial.println("Joints initialized...");
  PhoenixDrive_init(&drive, joints);
  Serial.println("Drive initialized...");
  PhoenixImu_init(&imu);
  /**
  for(int i=0;i<NUM_LINE_SENSORS;++i) {
    PhoenixLineSensor_init(&line_sensors[i]);
  }
  Serial.println("Line Sensors initialized...");
  PhoenixLineHandler_init(&line_handler, line_sensors);
  Serial.println("Line Handler initialized...");

  Timer_init();
  test1 = Timer_create(100, &testTimerFn, 0);
  struct Timer* test_joint_timer=Timer_create(1000, &testJointsFn, 0);
  Timer_start(test1);
  Timer_start(test_joint_timer);
  Serial.println("Timer initialized...");
  sei();
  **/
}

void loop() {

}
