//mingyu-force--������ �ƻ�������
inherit SKILL; 
#include <ansi.h>
void setup() 
{
        set("name", "������");
        set("usage/force", 1);
        set("usage/parry", 1);
        set("skill_class", "yihua");
        set("learn_bonus", 20);
        set("effective_level", 150);
        set("black_white_ness", 30);
        set("practice_bonus", 50);
}  
void skill_improved(object me)
{
        int s,diff;
        //10,30,50,70,100,140,170,210,250,    
        s = me->query_skill("mingyu-force", 1);
        switch(s)
        {
        case 10:
        if( !me->query("mingyu_mark/1") )
        {
        	tell_object(me,HIW"������Ŀ̿���ϰ����ġ������񹦡�ͻ�Ƶ�һ���ˡ�\n"NOR);
        	me->set("mingyu_mark/1",1);
        }
        	break;
        case 30:
        if( !me->query("mingyu_mark/2") )
        {
        	tell_object(me,HIW"������Ŀ̿���ϰ����ġ������񹦡�ͻ�Ƶڶ����ˡ�\n"NOR);
        	me->set("mingyu_mark/2",1);
        }
       		break;
        case 50:
        if( !me->query("mingyu_mark/3") )
        {
        	tell_object(me,HIW"������Ŀ̿���ϰ����ġ������񹦡�ͻ�Ƶ������ˡ�\n"NOR);
        	me->set("mingyu_mark/3",1);
        }
        	break;
        case 70:
        if( !me->query("mingyu_mark/4") )
        {
        	tell_object(me,WHT"������Ŀ̿���ϰ����ġ������񹦡�ͻ�Ƶ��Ĳ��ˡ�\n"NOR);
        	me->set("mingyu_mark/4",1);
        }
        	break;
        case 100:
        if( !me->query("mingyu_mark/5") )
        {
        	tell_object(me,WHT"������Ŀ̿���ϰ����ġ������񹦡�ͻ�Ƶ�����ˡ�\n"NOR);
        	me->set("mingyu_mark/5",1);
        }
        	break;
        case 140:
        if( !me->query("mingyu_mark/6") )
        {
        	tell_object(me,WHT"������Ŀ̿���ϰ����ġ������񹦡�ͻ�Ƶ������ˡ�\n"NOR);
        	me->set("mingyu_mark/6",1);
        }
        	break;
        case 170:
        if( !me->query("mingyu_mark/7") )
        {
        	tell_object(me,HIG"������Ŀ̿���ϰ����ġ������񹦡�ͻ�Ƶ��߲��ˡ�\n"NOR);
        	me->set("mingyu_mark/7",1);
        }
        	break;
        case 210:
        if( !me->query("mingyu_mark/8") )
        {
        	tell_object(me,HIG"������Ŀ̿���ϰ����ġ������񹦡�ͻ�Ƶڰ˲��ˡ�\n"NOR);
        	me->set("mingyu_mark/8",1);
        }
        	break;
        case 250:
        if( !me->query("mingyu_mark/9") )
        {
        	tell_object(me,HIR"��ϲ�㣡��ġ������񹦡�ͻ�ƵھŲ��ˣ���\n"NOR);
        	CHANNEL_D->do_sys_channel(
                	"info",sprintf("%s��%s"+"�Ѿ�ͻ���ˡ������񹦡��ھŲ㣬������ҪѪ���ȷ��ˣ�", NATURE_D->game_time(),me->name()));
        	me->set("mingyu_mark/9",1);
        }
        	break;
        default:
        	break;
        } 
}