
#include <project.h>

/***************************************
*          Constants
***************************************/

/* Mouse movement states */
#define MOUSE_DOWN                  (0u)  
#define MOUSE_LEFT                  (1u)
#define MOUSE_UP                    (2u)
#define MOUSE_RIGHT                 (3u)
#define MOUSE_LB                    (1u)

#define MOUSE_DATA_LEN              (3u)
//cursor step size
#define CURSOR_STEP                 (2)         


/***************************************
*       Function Prototypes
***************************************/
void HidsCallBack(uint32 event, void *eventParam);
void HidsInit(void);
void SimulateMouse(void);


/***************************************
* External data references
***************************************/
extern uint16 mouseSimulation;
extern uint8 protocol;  
extern uint8 suspend;
extern uint32 mouseTimer;



