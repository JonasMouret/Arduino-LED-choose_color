int redPin=11;           // Set the Red LED Pin to 11
int greenPin=10;         // Set the Green LED Pin to 10
int bluePin=6;           // Set the Blue LED Pin to 6
int redbrightness=255;   // Set Brightness to the Red LED
int greenbrightness=255; // Set Brightness to the Green LED
int bluebrightness=255;  // Set Brightness to the Blue LED 
String colorChoice;      // Set up variable to hold user input

void setup() {
  Serial.begin(9600);       // Turn on Serial port to 9600 baud
  pinMode(redPin,OUTPUT);   // Set up Pin Mode to OUTPUT
  pinMode(greenPin,OUTPUT); // Set up Pin Mode to OUTPUT
  pinMode(bluePin,OUTPUT);  // Set up Pin Mode to OUTPUT
}

void loop() {

  Serial.println ("Veuillez saisir la couleur de votre choix (rouge, vert, bleu ou entrez Off pour éteindre la LED) :");          // Prompting for User for Input
  while (Serial.available()==0){ }                                                                                                // Wait for User Input
  
  colorChoice = Serial.readString();                                                                                              // Read string from Serial port
  Serial.println ("------------------------------------");
  Serial.print ("Vous avez choisi la couleur : ");
  Serial.println (colorChoice);
  Serial.println ("------------------------------------");
  delay(1000);

  if (colorChoice=="rouge" or colorChoice=="Rouge"){                        // If User Input is == to red then execute the code 

      analogWrite(redPin,redbrightness);                                    // Turn on the Red LED
      analogWrite(greenPin,0);                                              // Turn off the Green LED
      analogWrite(bluePin,0);                                               // Turn off the Blue LED

  }

  if (colorChoice=="vert" or colorChoice=="Vert"){                          // If User Input is == to green then execute the code 

      analogWrite(redPin,0);                                                // Turn off the Red LED
      analogWrite(greenPin,greenbrightness);                                // Turn on the Green LED
      analogWrite(bluePin,0);                                               // Turn off the Blue LED

  }

  if (colorChoice=="bleu" or colorChoice=="Bleu"){                         // If User Input is == to BLUE then execute the code 

      analogWrite(redPin,0);                                               // Turn off the Red LED
      analogWrite(greenPin,0);                                             // Turn off the Green LED
      analogWrite(bluePin,bluebrightness);                                 // Turn on the Blue LED

  }

  if (colorChoice=="Off" or colorChoice=="off"){                          // If User Input is == Off the execute the code

    analogWrite(redPin,0);                                                // Turn off the Red LED
    analogWrite(greenPin,0);                                              // Turn off the Grenn LED
    analogWrite(bluePin,0);                                               // Turn off the Blue LED
  }

  if (colorChoice=="tout" or colorChoice=="Tout"){                        // If User Input is == tout or == Tout then execute the code
    
    analogWrite(redPin,redbrightness);                                    // Turn on the Red LED
    analogWrite(greenPin,greenbrightness);                                // Turn on the Green LED
    analogWrite(bluePin,bluebrightness);                                  // Turn on the Blue LED
  }

  if (colorChoice !="red" && colorChoice != "green" && colorChoice != "blue" && colorChoice != "Off") {       // If the user write a wrong Value the programme gonna ask to try again
    Serial.println ("Vous n'avez pas entrez une valeure correcte, choisissez entre red, green or blue");      // Prompt to the user to try again with a good value
    Serial.println ("");
  }

}
