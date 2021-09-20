# ESP32 Installation Manual
********************************************************************

Instead of commonly used ATmega328P Microcontroller (in Arduino UNO, Arduino Nano), ESP32 Microcontroller is used in this project.
You may have to install a ESP32 compiling module in Arduino IDE in order to detect your device.

```
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_dev_index.json
```

### Step 1: 
Select **Preferences** on Arduino IDE toolbar

<img width="746" alt="Step 1" src="https://user-images.githubusercontent.com/90884001/133961275-fa1f08db-ff6c-44a0-86ba-8a7ecfd0bd89.png">

### Step 2:
Edit the line **Additional Boards Manager URLs:**

<img width="722" alt="Step 2 _ New" src="https://user-images.githubusercontent.com/90884001/133971264-73cf3809-8316-4aee-894c-40d55b532ae9.png">

### Step 3:
Select **Tools -> Board -> Boards Manager**
Enter ```ESP32``` and INSTALL 1.0.6 version

<img width="799" alt="螢幕截圖 2021-09-20 下午3 24 04" src="https://user-images.githubusercontent.com/90884001/133968579-5b967694-57ed-402e-8325-6120ae2fc5e1.png">

### Step 4:
Restart the Arduino IDE and select the item on **Tools** as below:
- Board: ESP32 Arduino -> T-Beam
- Upload Speed: "115200"
- Port: ```Your USB Port Connected```

<img width="552" alt="Step 3" src="https://user-images.githubusercontent.com/90884001/133961758-a9bf2240-7fe3-45e5-b806-1ce5b56d9c88.png">

### Step 5:
Test your device with this sample script
Download here: [Device_Test.ino](https://github.com/CoWIN-Workshop/Pilot_Training01/blob/main/Samples/Device_Test.ino)

or copy and paste the below script:

```
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Test");
  delay(2000);
}
```

### Step 6:
Upload the script to the device by clicking the **ARROW UPLOAD** button and wait...

<img width="728" alt="Step 6" src="https://user-images.githubusercontent.com/90884001/133970682-705486f3-c1b3-42ef-b792-5bb12cca286f.png">

### Step 7:
Click the **Magnifier** (Serial Monitor) icon at the right-top corner and a screen will show the response from the device.

<img width="844" alt="Step 7" src="https://user-images.githubusercontent.com/90884001/133971605-5a134d83-ad9b-4ede-9d19-9e2977d92a87.png">
