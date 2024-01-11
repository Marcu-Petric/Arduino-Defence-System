# Arduino-Defence-System
This project combines the power of Arduino, radar technology, and lasers to create an innovative system capable of detecting and tracking objects. The radar, mounted on a servo motor, scans a specified range, and lasers are precisely positioned based on detected objects.

## Introduction

I happened to stumble upon a documentary that was showcasing the latest applications of radar sensors and laser technologies while exploring cutting-edge technologies. This got me interested in incorporating them into one of my own projects so that I chose Arduino as my starting point.

Therefore, I aimed at developing an interactive system with the capability of precise object detection and tracking. The idea was to use it near penitentiaries and at parks which are prone to animal attacks; places with forests or zoos.

In the course of project development, control algorithms were implemented on Arduino Uno board experimentally, allowing for functionality optimization. By interacting with Arduino and adjusting the project according to my personal needs, I could learn new things as well as gain experience in a creative way.

Consequently, I managed to create an integrated system using both radar and laser technologies with artistic aptitude. The project not only achieved its intended aim but also served as a source of pride and important experience in the realm of project development around Arduino.

##  System Design

### Components and Software Used

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

The chosen power supply operates at 5V with a maximum capacity of 2500mA. To assess its adequacy, we calculated the required current based on the technical specifications of individual components in the system. These include:

+ A sensor with a current consumption of 15mA,
+ Five motors, each with a current consumption of 190mA,
+ Two lasers, each with a current consumption of 30mA.
  
 By summing these values, we obtained the total current required for the operation of all components according to the formula:
  
  ![image](https://github.com/Marcu-Petric/Arduino-Defence-System/assets/87765474/98850df1-aa6b-43b9-a0bf-8e7003eb18e6)

  Based on these calculations, we concluded that the 5V power supply is suitable to support the operation of all components in the system, ensuring proper and efficient power supply for the entire system.

  












