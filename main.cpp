


#include <stdio.h>
#include <math.h>
#include "nodes.h"
#include "synth.h"

#ifdef WITH_GUI
#include "gui.h"
#endif

#ifdef RASPI
#include <pigpio.h>
#endif


/*******************************************************************/
int main(void);
int main(void)
{


#ifdef RASPI
    gpioInitialise();
    printf("GPIO lib initialized.\n");
#endif



    AudioEngine engine = AudioEngine();

#ifdef WITH_GUI

    NodeView nodeView = NodeView("Node Window", &engine);

#endif





    engine.Start();

    engine.AddCreators();

    engine.LoadNodes();

#ifdef WITH_GUI


    nodeView.Init();

    
    nodeView.Run();

    nodeView.Dispose();

    printf("Node view disposed.\n");

#else

    std::cin.get();


#endif



    engine.Save();

    engine.Dispose();

    printf("Audio engine disposed.\n");

#ifdef RASPI
   gpioTerminate();
   printf("GPIO lib terminated.\n");
#endif


    printf("Press [ENTER] to exit.\n");

    std::cin.get();

    return 0;

}