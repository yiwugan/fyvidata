inherit NPC; 
void create() 
{ 
        set_name("郭大娘", ({ "guo dama", "guo" }) ); 
        set("gender", "女性" ); 
        set("age", 50); 
        set("long", 
"没有人记得郭大妈是什么时候搬来桃园的，大家只记得当初她是带着一个半大 
的孩子来的，也没有人注意到孩子什么时候不见了。 \n");   
        set("combat_exp", 100); 
        set("attitude", "friendly"); 
        set("per",15); 
        set("chat_chance", 2); 
         
        set("chat_msg", ({ 
                "郭大娘叹了一口气说道：“江湖，江湖，一入江湖身不由己。。。”\n", 
                "郭大娘自言自语道：“我那儿，不知你带走的冬衣还保暖吗？”\n", 
                "郭大娘在屋内忙碌着。\n", 
        }) ); 
        setup(); 
         
    carry_object("/obj/armor/cloth")->wear(); 
    add_money("coin", 20); 
}   
int accept_fight(object me) 
{ 
        command("say 我老太婆哪里是您的对手？"); 
        return 0; 
}          
