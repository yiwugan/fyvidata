#include <ansi.h>
inherit "/d/taiping/npc/smart_npc";
inherit INQUIRY_MSG; 
int estate(); 
void create()
{
        set_name("����",({"han tang","han"}));
//      set("title","��������");
        set("long","
���Ĳ���Ұ���������׶�ֻ����üĿ��·����Ǵ���һ��˵��������Į֮
�⣬����˭��û���Ӻ����׽�������ȻҲ��Ը���κ����׽��������ʲô��
����������վ��ԶԶ�ġ��������߽����߳�֮�ڣ������̾ͻ��ߵø�ԶЩ��
�������ϲ�����ǰ��Ҳ����û���˼��������ڡ�\n");
        
        set("gender","����");
        set("group","ma");
        
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
                "�ϲ�": "�����ϲ���ʲô�����ǶԵģ������ϲ�������ô�����Ҷ�������Թ��",
           "����":"�����ϲ���ʲô�����ǶԵģ������ϲ�������ô�����Ҷ�������Թ��",
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
                "\n������������ԣ��������������ѱ�����ס�����;�������������
�������ڵ�����������\n",
        }) );                   
        
        auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_u","nine-moon-claw",1);
        
        setup();
        carry_object("/obj/armor/cloth")->wear();
 
}      
