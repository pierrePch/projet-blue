#include "../include/pwmServo/pwmServo.hpp"


int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "Controleur_pwm");
  	Servo pwmDir("direction");
	Servo pwmMot("moteur");
	Servo pwmSel("selecteur");
  
  ros::NodeHandle n;

  //Inscription aux 3 topics de commande
  
  //ros::Subscriber topicDir = n.subscribe("commandeDir", 1,boost::bind(&Servo::debug,_1));
   ros::Subscriber topicDir = n.subscribe("commandeDir", 1,&Servo::commande,&pwmDir);
  ros::Subscriber sub = n.subscribe("commandeMot", 1, &Servo::commande, &pwmMot);
  //ros::Subscriber sub = n.subscribe("commandeSel", 1, &Servo::commande, &pwmSel);

  //Essaye de recuperer autant de message asap
  ros::spin();

  return 0;
}