# picokey-playground
figuring out how tf to use the pi pico as a hid device in c++ (or at least thats the plan)

ToDo
+create rpnParser -class (or other method) to map inputs to controller
    +needs to be dynamic to be used in config file and be aplicable to all controllers (potentally inputs aswell as bonus)
    :could use names of inputs already defined in config as references, dereference them on process (security/ safety) and have a reference to controller var being updated
+create mouse controller to handle conglomerating inputs and sending to hid controller
    +modify/ create input class to dynamically set outputs to controller 
+create keyboard controller 
+create gamepad controller


Done
-panic over my ability to PROcrastinate (i'm a pro for a reason)
+merge work from last semester project into code base

Scrapped
unNeeded currently +make linux build script so i don't have to deal with odd/ dicrepit set ups between work stations