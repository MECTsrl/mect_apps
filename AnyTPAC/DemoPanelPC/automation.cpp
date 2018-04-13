#include "crosstable.h"
#include "automation.h"

void update_all_json();
void do_write_query();

/* put here the initalization */
void setup(void)
{
}

/* put here the operation made every 100ms */
void loop(void)
{
    do_write_query();
    update_all_json();
}

void update_all_json()
{
    static int counter = 0;

    // update each 0.5 s
    if (counter % 5 == 0) {

        FILE *file_json = fopen("/tmp/update_all.json", "w");
        if (file_json) {
            fprintf(file_json,
                    "Content-Type: application/json; charset=UTF-8\n"
                    "\n"
                    "{\n");

            fprintf(file_json, "\"theHEARTBEAT\" :\"%u\",\n", theHEARTBEAT);
            fprintf(file_json, "\"theLED\"       :\"%d\",\n", theLED);
            fprintf(file_json, "\"theBUTTON\"    :\"%d\",\n", theBUTTON);

            fprintf(file_json, "\"PLC_Year\"     :\"%u\",\n", PLC_Year);
            fprintf(file_json, "\"PLC_Month\"    :\"%u\",\n", PLC_Month);
            fprintf(file_json, "\"PLC_Day\"      :\"%u\",\n", PLC_Day);

            fprintf(file_json, "\"PLC_Hours\"    :\"%u\",\n", PLC_Hours);
            fprintf(file_json, "\"PLC_Minutes\"  :\"%u\",\n", PLC_Minutes);
            fprintf(file_json, "\"PLC_Seconds\"  :\"%u\" \n", PLC_Seconds);

            fprintf(file_json,"}\n");
            fclose(file_json);
        } else {
            fprintf(stderr, "update_all_json(): cannot write json\n");
        }
    }
    ++counter;
}

void do_write_query()
{
    FILE *file_query = fopen("/tmp/do_write.query", "r");

    if (!file_query) {
        return;
    }
    while (! feof(file_query)) {
        char name[42];
        int ivalue;

        if (fscanf(file_query, "%41[^=]=%d ", name, &ivalue) != 2) {
            fprintf(stderr, "bad fscanf\n");
            break;
        }
        if (strcmp(name, "theLED") == 0) {

            fprintf(stderr, "doWrite_theLED(%d)\n", ivalue);
            doWrite_theLED(ivalue);
        }
    }
    fclose(file_query);
    unlink("/tmp/do_write.query");
}

