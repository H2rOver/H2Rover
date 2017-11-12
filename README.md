# H2Rover Library Installation

Created By: Daniel Benusovich  
Created On: 26 October 2017  
Last Edited By: Daniel Benusovich  
Edited On: 11 November 2017  

## Purpose of Library
The purpose of this library is to ease access to the various components of the H2rOver system. Rather than having to power through extensive examples, this library will condense each component of the system to a couple lines that will initialize related components and allow easy development henceforth.

## Requirements

  1. Arduino Sketchbook is installed
     - Install here: https://www.arduino.cc/en/Guide/HomePage 
    
  2. Git is installed on the computer
     - Install here: https://git-scm.com/book/en/v2/Getting-Started-Installing-Git 
     - Verify installation by running the command “git” into the command line
    
  3. Ensure the following libraries are installed:
     - Adafruit Unified Sensor 
     - Adafruit BNO055
     - Xbee

## Cloning the Repository
  
  1. Navigate to the directory where Arduino is installed and enter the libraries folder.
       - Example Directory: C:\Program Files (x86)\Arduino\libraries
       
  2. Open a terminal inside the libraries folder.
       - On Windows the terminal console should read: “C:\Program Files (x86)\Arduino\libraries”
       
  3. Execute this command:
  
         git clone https://github.com/H2rOver/H2Rover.git
         
     - The folder should appear in the libraries folder named H2Rover


## Verification of Repository Import

1. In Arduino Sketchbook navigate to the proper place in the menu Sketch/Include Library
   - Check under the Contributed Libraries tab for H2Rover
   
2. If it is there you are done! Click on the library in the tab to import it into your project. 

3. If the library is not there please delete the H2Rover folder from its current location and try again. The repository has been cloned into the wrong folder so please start again from Cloning the Repository and find the proper location of the Arduino installation folder.

 ## Update the Library
The library will be periodically updated requiring one to run a command to update the library on local machines. Navigate to the folder where the library is contained and run the following command to update the repository:

    git pull
