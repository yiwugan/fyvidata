 // changelaw.c
inherit SKILL; 
void setup() {
        set("name",                             "�׾�");
        set("type",                                     "knowledge");
        set("usage/literate",           1);
        //set("learn_bonus",                      -50);
        //set("practice_bonus",           -50);
        set("black_white_ness",         10);
        set("effective_level",          200);
}  
int learn_bonus() {
        if(this_player()->query_skill("changelaw",1)<200)
                return -50;
        return 50;
}    
