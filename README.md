# Rope-Climbing-Robot
 A rope climbing robot is a type of robot that can move in-ground and also can climb a rope. This robot also performs various tasks like rescue operations and military operations. There are many ways to build a robot but nowadays most popularly wheeled mobile robots (WMR) are widely used.
<br/><br/>
# IDEATION OF OUR MODEL
The motivation of the robot is taken from our day-to-day life scenario in which people face carrying necessary things in various work. To solve the problem, we have come across this project to help people carry necessary things. Our main objective in building a rope climbing robot is to reduce human tasks. In a building, this rope climbing robot can be applied to transport necessary things from one floor to another floor and also transport casualties in rescue operations.
<br/><br/>
# DESIGNING OF OUR MODEL 
In this project, we will focus on building a rope climbing robot. We are designing our robot in such a manner that it consumes low energy and also is of low cost, easy to control, and built. We are designing a robot that climbs along a rope carrying a load and therefore can move across the space through the rope. We are using five DC motors, two Johnson motors, and one servo motor for making our robot. We are designing our robot in such a manner that it consumes low energy and also is of low cost, easy to control, and built. While making our robot we have focused on mainly two important aspects that is grip on the rope and smoothness of the movement. These two characteristics are important to carry weight with a robot and easy to maintain the overall stability of the robot. Our designed robot is planned to climb ropes vertically and can be manually controlled by using the mobile blynk app. The robot is planned to have, a design as simple as possible, and the overall cost is minimized for using the robot in practical situations.
<br/><br/>
# MECHANICAL ASPECT
* **GRIPPING MECHANISM** 
    * We are using one DC motor for the purpose of gripping and one servo motor, to help the gripper to move up-down. The Servo motor is connected to the base of the gripper and the DC motor with the help of two spare wheels and spur gear the gripping mechanism is made. 
![GRIPPER MECHANISM](https://user-images.githubusercontent.com/97011184/197997822-a573c1a1-68e5-44ae-adff-f69999fd415d.png)
* **CLIMBING MECHANISM**
    * We have designed the robot in such a way that there will be two Johnsons motors of 30 rpm each connected to the wheels. The wheels roll on the surface of the rope which is powered by the motor. In presence of sufficient friction between the wheels and the rope, the robot traverses the rope. The wheel should offer sufficient friction to support the robot in the vertical position. 
![CLIMBING MECHANISM](https://user-images.githubusercontent.com/97011184/197999583-a994cf1c-47fa-444c-896b-8721aac54492.png)
* **ELECTRONIC COMPONENT USE IN OUR PROJECT** 
    * ESP32 
    * DC motors 
    * Blynk App 
    * L298n motor controller 
    * Adapter 
    * Connecting wires and jumpers 
    * Johnson Motor
![ELECTRONIC COMPONENTS](https://user-images.githubusercontent.com/97011184/198001571-8d865a5c-a2c1-4a37-ae36-7f931041cd23.png)
# CIRCUIT DIAGRAM
![WhatsApp Image 2022-10-28 at 23 35 37](https://user-images.githubusercontent.com/97011184/199406823-153a56c7-001c-4b39-8fd4-278af672e32a.jpeg)
![WhatsApp Image 2022-10-28 at 23 35 48](https://user-images.githubusercontent.com/97011184/199406839-2764230c-7771-45e5-b806-60acf0897a03.jpeg)
* **BOT SPECIFICATIONS**
    * Weight of the Bot = 1.605 Kg 
    * Dimensions of the Bot = 22x23x13 cm (excluding the extended gripping mechanism) 
    * Total No of base Motors = 4 (100 rpm) 
    * Total No of climbing Motors = 2 (30 rpm) 
    * Rated torque of base motors = 9.4 Kg-cm 
    * Rated torque of climbing motors = 2 Kg-cm 
    * Diameter of all the wheels used in the Bot = 7 cm 
    * Time required to climb 100cm = 10sec (approximation) 
    * Climbing Speed = 10 cm/s = 0.1 m/s
* **TOTAL HORIZONTAL PAYLOAD**
    * As the radius of the wheels is not 1cm, therefore torque delivered to each wheel will be lesser than the theoretical value.
    * Total weight that each wheel can easily carry = 2 𝑘𝑔𝑐𝑚/ 3.5𝑐𝑚 = 0.571 𝑘𝑔 
    * Total weight that can be carried by the Bot = 0.571x4 = 2.2 Kg 
    * Therefore, the Bot can easily carry a weight of 2.2 Kg
* **TOTAL VERTICAL PAYLOAD**
    * Total weight that each climbing motor can lift = 9.4 𝑘𝑔𝑐𝑚/3.5𝑐𝑚 = 2.685 𝑘𝑔
    * Total Weight that the whole Bot can lift = 2.685x2 = 5.37 Kg 
    * Therefore, the Bot can easily lift weights up to 5.37 Kg 
<br/><br/>
# APPROXIMATE COST OF THE BOT
![APPROXIMATE COST](https://user-images.githubusercontent.com/97011184/198004668-82cf9c49-edfb-4c4f-a6f0-e860ec4e6276.png)
# CONTROLLING OF OUR ROBOT 
We will control our robot by using blynk app and Bluetooth present in the ESP32 module. In the blynk app, we have made step by step button for controlling our robot as given <br/>
Step 1: Release the gripper <br/> 
Step 2: Grab the load <br/>
Step 3: Move through a distance <br/> 
Step 4: Grab the rope <br/>
Step 5: Climb through the rope <br/> 
![BLYNK APP](https://user-images.githubusercontent.com/97011184/198005997-0320422e-6205-4894-bbd1-2e14fa377e89.png)
# APPLICATION 
    * Our robot can carry weights to a certain height and also it can drop weights from some height. 
    * When equipped with a camera, the robot can be used for surveillance. 
    * It can be used for cleaning purposes to clean the glass of windows and walls of the building. 
    * The robot can be used to take pictures or to make videos from different heights. FUTURE 
# FUTURE IMPROVEMENTS 
    * In our robot, we can improve the load-carrying capacity using some stronger motors. 
    * We can improve the software part to detect the rope if the rope has some not or is bent. 
    * We can improve the climbing mechanism of our robot so that it can climb on any type of rope.
# REFERENCES 
http://www.mecs-press.org/ijisa/ijisa-v5-n9/IJISA-V5-N9-1.pdf https://www.researchgate.net/publication/327287370_Design_and_Analysis_of_SpringBased_Rope_Climbing_Robot_Proceedings_of_iNaCoMM_20
