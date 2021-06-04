void Check_Serial_Input() {
  
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    int Command_Last = Command;
    Command = Serial.read();
    if (Command == 10) Command = Command_Last;

    // Print Comamnd to Serial Monitor
    if (Command != 0) {
        Serial.print(F(""));
        Serial.print(F("Command: "));
        Serial.println(Command);
        }
  }

Execute_Serial_Command();
}


void Execute_Serial_Command() {
// Rotate 20 degrees CCW

if (Command == 104) {                   // letter r
    Command = 0;
    Serial.println(F("  "));
    Serial.println(F("  "));
    Serial.println(F("        HELP MENU"));
    Serial.println(F("      Enter the following letter"));
    Serial.println(F("  --------------------"));
    Serial.println(F("  a"));
    Serial.println(F("  b"));
    Serial.println(F("  c = Goto Charging Station")); //99
    Serial.println(F("  d = Set to Docked"));         // 100                
    Serial.println(F("  e = Exit dock"));             //101
    Serial.println(F("  f"));
    Serial.println(F("  g"));
    Serial.println(F("  h = Help Menu"));             //104
    Serial.println(F("  i"));
    Serial.println(F("  j"));
    Serial.println(F("  k"));
    Serial.println(F("  l"));
    Serial.println(F("  m = Manuel Mode"));
    Serial.println(F("  n"));
    Serial.println(F("  o"));
    Serial.println(F("  p = Pause/Park Mower"));      //112
    Serial.println(F("  q = Quick Start Mower"));     //113
    Serial.println(F("  r = Rain Sensor ON/OFF"));    //114
    Serial.println(F("  s"));
    Serial.println(F("  t"));
    Serial.println(F("  u"));
    Serial.println(F("  v = Fake Voltage of 12.6V"));                         //118
    Serial.println(F("  w = Fake Wire Signal ON/OFF"));
    Serial.println(F("  x"));
    Serial.println(F("  y"));
    Serial.println(F("  z = Fake All Volts, Wheel Amps "));    //122"));
    Serial.println(F("  "));
    Serial.println(F("  "));

        
    delay(7000);   
    }

if (Command == 99) {                   // letter c
    Command = 0;
    Manouver_Go_To_Charging_Station();
    }

if (Command == 100) {                   // letter d
    Command = 0;
    Mower_Docked = 1 ;
    Mower_Parked = 0 ;
    }

if (Command == 101) {                   // letter e
    Command = 0;
    Alarm_Start_Exit_Zone_2();
    }

if (Command == 109) {                   // letter m  
    Command = 0;
    Manouver_Park_The_Mower(); 
    delay(100);
    Manouver_Manuel_Mode(); 
    Turn_On_Relay();
    }

if (Command == 112) {                   // letter p  
    Command = 0;
    Manouver_Park_The_Mower();
    }

if (Command == 113) {                   // letter q  
    Command = 0;
    if (Mower_Docked == 1) {
      Serial.println(F("Overriding Docked Status - Starting Mower"));
      delay(2000);
      Mower_Docked = 0;
      }
    Alarm_Start_Quick_Go();
    }


if (Command == 114) {                   // letter r
    Command = 0;
    if (Rain_Sensor_Installed == 0) {
      Rain_Sensor_Installed = 1;
      Serial.println(F("Rain Sensor Enabled = ON"));
      }
    if (Rain_Sensor_Installed == 1) {
      Rain_Sensor_Installed = 0;
      Serial.println(F("Rain Sensor Enabled = OFF"));
      }
    }


if (Command == 118) {                   // letter v  
    Command = 0;
    }

if (Command == 119) {                   // letter w
    Command = 0;
    bool Skip = 0;
    if (Fake_Wire == 0) {
      Fake_Wire = 1;
      Serial.println(F("Fake_Wire Signal Enabled = ON"));
      Skip = 1;
      }
    if ((Fake_Wire == 1) && (Skip == 0)) {
      Fake_Wire = 0;
      Serial.println(F("Fake_Wire Signal Enabled = OFF"));
      }
    }


if (Command == 122) {                   // letter v
    Command = 0;
    int Skip = 0;

    
    if (Fake_All_Settings == 0) {
      Serial.println(F(""));
      
      Wheel_Amp_Sensor_ON = 0;      
      Fake_All_Settings = 1;     

      Serial.println(F(""));
      Serial.println(F("Fake Volts Enabled = ON"));
      Serial.println(F("Wheel Amp Sensor Disabled"));
      Serial.println(F("Fake Settings ON !!!"));
      Serial.println(F(""));
      Skip = 1;
      }
    
    
    if ((Fake_All_Settings == 1) && (Skip == 0)) {
      Serial.println(F(""));
      
      Perimeter_Wire_Enabled = 1;
      Wheel_Amp_Sensor_ON = 1;
      Fake_All_Settings = 0;
      
      Serial.println(F(""));
      Serial.println(F("All Sensors normal status"));
      Serial.println(F(""));
      }
    

    }

}





void Check_Mower_Status() {
      Serial.println("");
      Serial.print(F("Mower Status:  "));
      Serial.print(F("Parked ="));
      Serial.print(Mower_Parked);
      Serial.print(F(" | Docked = "));
      Serial.print(Mower_Docked);
      Serial.print(F(" | Tracking = "));
      Serial.print(Tracking_Wire);
      Serial.print(F(" |  Exit Dock = "));
      Serial.print(Exiting_Dock);
      Serial.print(F(" |  Error Value = "));
      Serial.print(Mower_Error_Value);
      Serial.println("");
      } 
