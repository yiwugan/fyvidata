#include <ansi.h>
inherit "/d/taiping/npc/smart_npc";
inherit INQUIRY_MSG; 
void create()
{
        set_name("���㴨",({"lv xiangchun","lv"}));
        set("title",WHT"���ʱ��"NOR);
        set("long","
���㴨�Ǹ���ɫ�԰ף����ʱ����ˡ����Ա���������͹�������������
��Ϊ����û��ʲô�˲������ִ��󲻵���Ц�����ҿ��¡����㴨����������
������������֣�Ҳ��������������ڰ�������֮һ�����������ڻ���һ��
�İ�����������Ҳû���κ����ܱȵ���������\n");
        
        set("gender","����");
        
        set("age",32);          
        set("int",52);
        set("cor",30);
        set("cps",20);
        set("str",40);
        
        set("force",1500);
        set("max_force",1500);
        set("force_factor",120);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",8500000);  
        set("attitude", "friendly");
        
        set("resistance/kee",30);
        set("resistance/gin",30);
        set("resistance/sen",30);
        
        set("inquiry", ([
 
        ]));
        
        set("nb_chat_chance", 100);
           set("nb_chat_msg_combat", ([ 
        ]) );           
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
             (: auto_smart_fight(30) :),
        }) );
        set("chat_chance",1);
        set("chat_msg",({
                
        }) );                   
        
        auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","tanzhi-shentong",1);
        
        setup();
        carry_object(__DIR__"obj/cyancloth")->wear();
 
}     
