//magic@qy

#include <ansi.h>


inherit ITEM;

void create()
{
        set_name("ɽ�μ���",({"jiduan"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
                HIG "һ��ҩζʮ��ļ��Σ���������θ�ڴ󿪣�����һ����ҩ�ü�ֵ��\n"NOR);
                set("unit","��");
                set("value", 100000);
        }
}
void init()
{
        add_action("eat_guo","eat");
}
int eat_guo(string arg)
{
        int m_kee;
        int m_sen;
        int m_gin;
        int m_force;
	object me;
	me=this_player();
        if ( arg == "jiduan"){
	if(me->is_busy()){
	    write("��������æ��\n");
	    destruct(this_object());
            return 0;
	}
                m_kee = this_player()->query("max_kee");
        m_sen = this_player()->query("max_sen");
        m_gin = this_player()->query("max_gin");
        m_force = this_player()->query("max_force");
        message_vision(HIW"$N�綼�������﷢���ˣ��Ȳ������ذ�һ���̵�ɽ�μ��γԵ�һ�㲻ʣ��\n"NOR,this_player());
        this_player()->set("eff_kee",m_kee);
        this_player()->set("kee",m_kee);
        this_player()->set("eff_gin",m_gin);
        this_player()->set("gin",m_gin);
        this_player()->set("eff_sen",m_sen);
        this_player()->set("sen",m_sen);
        this_player()->set("food",100);
        destruct(this_object());
        return 1;
     }
     return 0; 
}
