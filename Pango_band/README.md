# *Pango Band*

## **Problem Statement :**

2020 is clearly not the year humanity can be very proud of. All hell broke lose since the beginning and even though we have a lot to worry about as of now, *COVID-19* is clearly the elephant in the room. We haven't cracked the 'code' on this one ( A little techie touch :)). YET! So in this case, prevention is literally better than cure. ( *If you think about it, a mask ain't that bad compared to a ventilator down your throat 🤷‍♀️*). Some of the measures we can take are as follows:

- Staying at home.*(Duh.*)
- Washing hands with alcohol-based soap or hand wash regularly. (*Now that's some solid advice. Looking at you hostelers😕*)
- Maintaining distance from others. (*We are engineers, so....*)
- Covering face with a mask or a cloth.

We are frequently emphasized to keep a minimum distance of 1.5 m between people and *sanitize hands* frequently and keep a regular check on our health conditions.

*Social distancing* matters a lot now as lock down has been lifted officially. Returning back to normalcy is as necessary as the cure. So we have to stay apart to do our part but people are not following that (*Not very cool of you people😐*) and they tend to forget the actual situation we are in. Washing hands regularly or sanitizing hands for every 30 minutes is clearly mandatory in this  time of crisis . But, we don't remember to do this in our daily schedules (*Not blaming or judging anyone, we all forget stuff😁*).

So, a device that always alerts you and *keeps you in track of your health condition* can come in handy. This is very essential to tackle the present situation smartly. **drum rolls* * Introducing Pango, our smart and simple solution to the existing crisis. **drum roll ends** 

## **Real time usage :**

This  **PANGO** band makes things simple for us by alerting us precisely. It reminds us to wash or sanitize our hands for every 30 mins through a buzzer alert. It alerts us to maintain distance from other person when we go close to the person by blinking red led ( *Now that's the cool stuff😎*). It notifies us about our body temperature. If it gets greater than normal body temperature (37.5℃ or 99.5℉) it enlightens a led so that we can take proper medication ( *In short, it knows how hot you are 😉* ). It's simple. It's Portable . It's user friendly . It's **Pango**.

## **Working :**

**PANGO** band is an ESP8266 based band ( *Quite technical, but important, I swear 😢* ) which helps us to maintain social distance from others in our workplace or at any public places, to disinfect our hands time to time and to monitor our body temperature 24/7.

LM 35 is a precision integrated circuit temperature sensor which monitors temperature based on ADC function. It has 3 pins: V in for the supply (5 V), Ground for ground(0 V), Output for the output (analog pin of micro controller). If the body temperature is greater than normal human body temperature the led glows.

Piezo buzzer generates sound by inverse principal of piezo electricity. It has 2 pins in which one is attached to a PWM pin and the other is connected to the ground. It sounds for every 30 mins indicating us to clean our hands . 

***( Beep Beep! Who is it? Pan. Pan who? Pan-' Go wash your hands!'🤣 )*** 

The band has a unique SSID and password same like a Wi-Fi router. The band is constantly present in access points (it acts as host for other band to connect) and station mode (it searches for other source to connect). Simply, a band which is acting like an access point is also searching for a Wi-Fi (another band). The band constantly checks for the presence of another band near to it. When it senses that there is a band near to it, it will find out the distance between 2 bands using RSSI . If the signal strength is greater than the threshold strength it blinks led as an indication to maintain distance and led goes off when the distance is maintained.

Note: The ESP doesn’t get confused between its own access point and others because the software of ESP enables it to ignore its own SSID even though it is searching for other access points of same name ( *ESP's are selfless bros ✌ *respect**, **clap clap**).

## **A little about RSSI:**

RSSI Stands for received signal strength intensity and it basically it tells you about the relationship between distance versus received signal strength. Well, there are very complex formulas available in the research papers to calculate the precise distance between the transmitter and the receiver but just for the sake of keeping the project-based simple, we haven't taken that route.


## **Challenges** Faced **and Rectification :**

1. Measuring distance 
    
    Let's face it, it's pretty difficult for a concoction so simple to include image detection and processing. We had to go for alternate ways to make this work ( *So we did some Jugaad*  ;) **).  To rectify this problem, we used signal strength between two bands ( Through RSSI calculation as aforementioned) so that we can know the distance between two people.
    
    Now we can hear what you are saying, "How can a band work on its own without another, team Pango?". It's true,  but the band is more centered towards commercial and industrial use, so the problem negates itself 🤷‍♂️🤷‍♀️ ( *That's how gender equal we are 😎* )
    
2. Alarm Trouble
    
    So when it comes to the reminder alarm, there were a lot of problems. "Should we add a Real time clock?", "Should we incorporate NTP?" Because we need a grasp of time to not disturb the users overnight. But then we added a switch ( Again. Jugaad 😉 ) so the user can decide when the alarm should be on. This also helps them customize the band, helping us to eradicate problems like that of what Night shift workers may face.
    

## **Conclusion :**

Following the COVID-19 outbreak, social distancing, wearing mask and maintaining hygiene is heavily needed. As Corona doesn’t have any cure yet (*More like GO! Rona🤷‍♂️* ), we have to follow the precautions and norms even after lock down.

This smart way of using technology and IOT will break the virus chain and helps us to combat the situation to some extent.

> Wear Pango , Stay cool, Stay Safe.
