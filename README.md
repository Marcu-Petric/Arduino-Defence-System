# Arduino-Defence-System
This project combines the power of Arduino, radar technology, and lasers to create an innovative system capable of detecting and tracking objects. The radar, mounted on a servo motor, scans a specified range, and lasers are precisely positioned based on detected objects.

## Author

Hotea Alexandra Maria | 2nd Year Automation | Technical University of Cluj-Napoca
Petric Marcu Cristian | 2nd Year Computer Science | Technical University of Cluj-Napoca

## Introduction

I happened to stumble upon a documentary that was showcasing the latest applications of radar sensors and laser technologies while exploring cutting-edge technologies. This got me interested in incorporating them into one of my own projects so that I chose Arduino as my starting point.

Therefore, I aimed at developing an interactive system with the capability of precise object detection and tracking. The idea was to use it near penitentiaries and at parks which are prone to animal attacks; places with forests or zoos.

In the course of project development, control algorithms were implemented on Arduino Uno board experimentally, allowing for functionality optimization. By interacting with Arduino and adjusting the project according to my personal needs, I could learn new things as well as gain experience in a creative way.

Consequently, I managed to create an integrated system using both radar and laser technologies with artistic aptitude. The project not only achieved its intended aim but also served as a source of pride and important experience in the realm of project development around Arduino.

##  System Design

### Components and Software Used

+	Arduino Uno Rev3 SMD – the microcontroller,

![image](https://github.com/Marcu-Petric/Arduino-Defence-System/assets/87765474/73116c26-441d-4341-97ea-95eb80104fc4)

+	Ultrasonic Sensor HC-SR04 – for detecting object and the distance to them,

![image](https://github.com/Marcu-Petric/Arduino-Defence-System/assets/87765474/25d2e0a3-2d87-479c-975e-4567b602b292)

+	Motor Servo SG90 – 5 buc. – for moving the lasers and the ultrasonic sensor,

 ![image](https://github.com/Marcu-Petric/Arduino-Defence-System/assets/87765474/66578fca-2532-41ab-8b46-f0615f38eeb7)

+	Laser Diode – 2 buc. – for "shooting" intruders,

![image](https://github.com/Marcu-Petric/Arduino-Defence-System/assets/87765474/11beb355-7caa-4e85-85e4-aeb0ce908fd3)

+	Breadboard 830 points – pentru connecting the components to power supply,

![image](https://github.com/Marcu-Petric/Arduino-Defence-System/assets/87765474/5f745c31-5bf7-4ef5-882f-a064b9bdc602)

+	Power Supply – 5.0V, 2500mA,
+	Arduino IDE 2.2.1 – software used fo programming the microcontroller,
+	TinkerCad – web page for designing the circuit diagram.


###  Component Testing

After ensuring the proper functionality of the Arduino microcontroller and configuring the motors for precise positioning, we dedicated efforts to test the ultrasonic sensor. We conducted a detailed investigation into the characteristics and operation of this sensor, subsequently developing a simple code to assess its performance in distance measurements.

Through the created code, we verified the responsiveness and accuracy of the ultrasonic sensor in measuring distances to objects in its proximity. Repeated tests allowed us to fine-tune and optimize the sensor settings to ensure reliable and consistent data.

In the motor testing process, our focus was on aligning them at a reference angle of 0°, providing valuable insights into their mounting in the project. The next step involved observing their movement at 180°, confirming the correct rotation direction and ensuring it aligned with our requirements.

Each step in component testing aimed not only at ensuring individual functionality but also at guaranteeing efficient interaction between them within the integrated system. These detailed tests played a crucial role in laying the foundation for the subsequent implementation of the control algorithm and ensuring the cohesion of the entire Arduino project with radar and lasers.

### Solution Description

The proposed solution for the project, aimed at detecting foreign objects and positioning lasers, involves a series of ingenious components and configurations. We mounted the radar on a servo motor to expand its visibility range, allowing it to rotate within a variable angle between 15° and 165°. This approach extends the coverage area of the radar and enhances the system's efficiency in detecting objects from various directions.

Lasers are positioned on two distinct motors. The first motor, responsible for horizontal positioning, adjusts the laser angle based on the motor's angle and the distance to the object detected by the radar. The second motor handles vertical positioning, taking into account the distance to the object. This two-dimensional configuration ensures precision and high speed in directing laser beams toward the object.

The use of two lasers contributes to optimizing response time in the detection of multiple objects and reduces the probability of positioning errors. As a result, lasers are activated sequentially with each detection of a new object, ensuring that each object receives the appropriate attention.

Information provided by the radar is captured and interpreted by the Arduino board. The interpretation algorithm calculates the necessary positions for the laser motors. The specific formulas for these positions are detailed in section 2.5, providing a clear explanation of how the Arduino board transforms received data into precise laser movements.

The chosen 5V power supply was selected for compatibility with all components, and the 2500mA power provides sufficient energy to operate all system elements, except for the Arduino board, which is connected to the computer via an A-B type USB cable. Connections between the ground and power of the source and components are made through the breadboard, and the components communicate directly with the microcontroller through the board's I/O pins. This configuration ensures efficient integration and correct communication between all system elements, contributing to the project's smooth operation.

### Circuit Schematic

To ensure an efficient and proper implementation of the project, we created an Circuit schematic using the TinkerCad website. We utilized the simulation option to test the integrity of the components and validate the correct functioning of the entire system.

![image](https://github.com/Marcu-Petric/Arduino-Defence-System/assets/87765474/ad898954-62a4-4e54-8dc7-9d5b272c08f3)

The chosen power supply operates at 5V with a maximum capacity of 2500mA. To assess its adequacy, we calculated the required current based on the technical specifications of individual components in the system. These include:

+ A sensor with a current consumption of 15mA,
+ Five motors, each with a current consumption of 190mA,
+ Two lasers, each with a current consumption of 30mA.
  
By summing these values, we obtained the total current required for the operation of all components according to the formula:
  
![image](https://github.com/Marcu-Petric/Arduino-Defence-System/assets/87765474/98850df1-aa6b-43b9-a0bf-8e7003eb18e6)

Based on these calculations, we concluded that the 5V power supply is suitable to support the operation of all components in the system, ensuring proper and efficient power supply for the entire system.

### Formulas for positioning the lasers

#### First case, when the angle of ultrasonic sensor's motor is smaller then 90&deg;.

![image](https://github.com/Marcu-Petric/Arduino-Defence-System/assets/87765474/d5d834cd-ffe8-47f8-8b0c-ae4f83b2d0a5)

#### Second case, when the angle of ultrasonic sensor's motor is bigger then 90&deg;.

![image](https://github.com/Marcu-Petric/Arduino-Defence-System/assets/87765474/c5b0ae09-e696-4f01-85cf-cb87bbf2a46a)

#### Third case, when the angle of ultrasonic sensor's motor is exacly then 90&deg;.

![image](https://github.com/Marcu-Petric/Arduino-Defence-System/assets/87765474/60e04662-db01-43b1-a7e0-4d0520af0edb)

## Experiments

### Experiment Premise

To assess the prototype's efficiency in identifying and "tranquilizing" foreign objects, we conducted experiments focusing on variables such as the number of objects and their distance from the radar. The results were expressed as percentages of correct positioning. Anticipating the outcomes, we formulated expectations based on the following considerations:

+ Distance from the Radar: We expected the percentage of laser positioning accuracy to increase as objects approached the radar. This is due to the fact that the degree range in which the laser angle will be correctly positioned is larger when objects are in proximity to the radar.

+ Number of Objects: Considering the limitations of the ultrasonic sensor, we anticipated that it would not detect the object in a single angle but rather in an angle interval depending on the distance from the radar. Consequently, there was a risk of the "giant object" effect when dealing with multiple objects. This means that instead of detecting several separate objects, the sensor might fail to distinguish between them. Therefore, with fewer objects, the accuracy percentage was expected to be higher.

### Experiment Results

For each cell in the table, we placed the respective number of objects in 10 different ways at the chosen distance. We counted the objects for which one of the lasers was correctly positioned in a complete radar cycle (from 15° to 165° and back to 15°). The result is expressed in percentages according to the formula:

![image](https://github.com/Marcu-Petric/Arduino-Defence-System/assets/87765474/11f2bde7-04e9-4dd1-98b1-79de30119710)

The result of the calculations is the one indicated in the respective cells.


| Number of objects / Distance | 10 cm | 20 cm | 30 cm |
|---------------|----------|-------|-------|
| One object     | 90%      | 100%  | 85%   |
| Two objects  | 95%      | 90%   | 85%   |
| Trei objects  | 90%      | 87%   | 87%   |


The best percentage was achieved at a distance of 10cm, aligning with our expectations. Despite our initial assumptions, due to the chosen algorithm, the radar successfully differentiated between objects. In the tests involving three objects, similar results were obtained compared to scenarios with two or just one object.

## References

+ Michael Margolis, _Arduino Cookbook_, second edition (O'Reilly Media, 2011), 
+ Franco P. Preparata, _Michael Ian Shamos_, Computational Geometry, (Springer, 1985).












