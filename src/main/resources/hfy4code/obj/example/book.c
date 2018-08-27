// An example book

inherit ITEM;

void create()
{
        set_name("白家拳法要旨", ({ "book" }));
        set_weight(600);
        set("unit", "本");
        set("long",
                
"这是一本介绍 白家拳法的入门书，柳家拳法是雪亭镇柳老拳师祖传的拳法\n"
                
"，易学易懂，这本书虽然只介绍了柳家拳初入门的功夫，但是用来防身已\n"
                "经算不错了，适合初学者。\n");
        set("value", 100);
        set("skill", ([
                "name":                 "bai-quan",             // name of 
                "exp_required": 0,                              // minimum 
                "sen_cost":             40,                             // 
                "difficulty":   20,                             // the base 
                "max_skill":    10                              // the 
        ]) );
}
 
