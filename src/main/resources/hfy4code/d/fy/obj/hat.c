 // hat.c
#include <armor.h> 
inherit HEAD; 
void create()
{
        set_name("����", ({ "hat" }) );
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 100);
                set("material", "wood");
                set("armor_prop/armor", 4);
                set("armor_prop/spirituality",3);
                set("armor_prop/intelligence",12);
                 set("skill", ([
                        "name":         "xisui",        
                        "exp_required": 20000,                          
                        "sen_cost":     10,                             
                        "difficulty":   10,             
                        "max_skill":    100             
                ]) );               
        }
        ::init_head();
} 
