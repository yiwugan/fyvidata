 // silencer@fy4
#include <ansi.h> 
inherit SSERVER; 
int conjure(object me, object target)
{
        object sword;   
        int skill;
        object *inv, ob;
        int i;
        
        seteuid(getuid());
                
        if( me->is_fighting() )
                return notify_fail("�㻹���Ȱѵ��˴�����˵�ɣ�\n");
        
        if (me->query("class")!="wudang")
                return notify_fail("ֻ���䵱���Ӳ������˽���.\n");
        
        if (me->query_skill("sword",1)<100)
                return notify_fail("��Ľ���̫����.\n");
                
        if (me->query_skill("incarnation",1)<100)
                return notify_fail("������������Բ���.\n");
                
        if (me->query("atman")<110)
                return notify_fail("�����������.\n");
        
        if (me->query("gin")<110)
                return notify_fail("��ľ�������.\n");
               
        if ((me->query_skill("sword",1)>400) && (me->query_skill("incarnation",1)>300))
        {
        	inv = all_inventory(me);
                for(i=0;i<sizeof(inv);i++){
                ob = inv[i];
                if(ob->query("name")== HIY"��"NOR
                        ||ob->query("name")== HIG"ľ��"NOR
                        ||ob->query("name")== HIW"ֽ��"NOR
                        ||ob->query("name")== HIR"�Ľ�"NOR
                        ||ob->query("id") == "forcesword")
                        {
                        return notify_fail("���Ѿ���һ�����ƵĽ��ˡ�\n");
                }
           }
               	sword = new("/obj/weapon/sword_heart");
                sword->move(me);
                message_vision("$N���̽����ľ���"+HIR"�������������޽��������ġ�����Ϊ�����˽�Ϊ�ģ�\n"NOR,me);
                message_vision(HIY"$N����ͻȻ���ų���â�����˵�����������˷���ɢ��ȥ......\n"NOR,me); 
                tell_object(me,"��âɢȥ��һ��"+sword->name()+"�����������У������ϴ������������о���Ѫ������ϵ.\n");
                return 1;
        }
                      
                        
        inv = all_inventory(me);
        for(i=0;i<sizeof(inv);i++){
                ob = inv[i];
                if(ob->query("name")== HIY"��"NOR
                        ||ob->query("name")== HIG"ľ��"NOR
                        ||ob->query("name")== HIW"ֽ��"NOR
                        ||ob->query("name")== HIW"�Ľ�"NOR
                        ||ob->query("id") == "forcesword")
                        {
                        return notify_fail("���Ѿ���һ�����ƵĽ��ˡ�\n");
                }
        } 
        
        
// if (me->query_temp("sword_number")==1)
//              return notify_fail("���Ѿ���һ�ѽ���.\n"); 
                
        skill=(me->query_skill("incarnation",1)+me->query_skill("sword"))/200;
        
        me->add("atman", -100);
        me->receive_damage("gin", 100); 
        tell_object(me,"�㰵�̽����ľ���"+HIG"�޴����ɽ������ﲻ�ɽ������²��ɽ���\n"NOR);
        message_vision(HIY"$N����һ�����һ������......\n"NOR,me); 
        me->start_busy(2);
        
        switch( skill ){
        
        case 0: 
                return notify_fail("��һ������\n");
                break;
        case 1:
                sword = new("/obj/weapon/sword_gold");
                sword->move(me);
                break;
        case 2: 
                sword = new("/obj/weapon/sword_wood");
                sword->move(me);
                break;
        default:
                sword = me->query("open_sesame") ? 
                                  new("/obj/weapon/sword_cq") 
                                : new("/obj/weapon/sword_paper");
                sword->move(me);
                break;
        }
//      me->set_temp("sword_number",1); 
        tell_object(me,"��õ���һ��"+sword->name()+".\n");
        return 1;
}      
