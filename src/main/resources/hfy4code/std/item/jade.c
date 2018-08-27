//code by xiaolang@fy.sumxin.com
#include <dbase.h>
#include <move.h>
#include <name.h> 
#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_MOVE;
inherit F_NAME; 
void create() {
        if(clonep(this_object())) {
                destruct(this_object());
                return notify_fail("CAN NOT CLONE STARNDARD OBJECT!\n");
        }
        set("inset",1);
} 
void init_item() { 
}  
void init() {
        add_action("do_inset", "inset");
}
int do_inset(string arg) {
	object me, stone,ob;
        string obj, item, p,name;
        int i,j,h,addjade;
        string m;      //����ȡstone������
        int n;         //����ȡ�˺�
        
        me = this_player();
        
        if(!arg) {
                return notify_fail("��Ҫ��Ƕʲô������\n");
        }
        if(!sscanf(arg, "%s in %s", item,obj)) {
                return notify_fail("��Ҫ��ʲô��Ƕ�����(inset xxx in xxx)\n");
        }
        ob = present(obj, me);
        stone = present(item, me);
        
        if(!objectp(ob) || !objectp(stone)){
                return notify_fail("��û����Щ������\n");
        }
        if( !ob->query("hole") ) {
                return notify_fail(ob->name()+"û�а��ۣ�����ô��Ƕ����\n");
        }
        if(!stone->query("inset")){
                return notify_fail(stone->name()+"������������Ƕ��\n");
        }
        if( ob->query("����/damage_type") && stone->query("����/damage_type") && ob->query("����/damage_type") != stone->query("����/damage_type") ){
        	return notify_fail("���Ѿ���Ƕ��һ�������˺����͵ı�ʯ�ˡ�\n");	
        }
        
        i=(int)stone->query("level");
        j=(int)ob->query("level");
        h=(int)ob->query("hole");
        addjade=(int)ob->query("add_jade");
        p=(string)ob->query("long");
        name=(string)ob->query("name");
        if( j <= 5 && j > 2 ){
        	if(i<2) return notify_fail(stone->name()+"�䲻��"+ob->name()+"�ˡ�\n");	
        }else if( j < 8 && j > 5 ){
        	if(i<5) return notify_fail(stone->name()+"�䲻��"+ob->name()+"�ˡ�\n");	
        }else if(j >= 8){
        	if(i<8) return notify_fail(stone->name()+"�䲻��"+ob->name()+"�ˡ�\n");	
        }
        message_vision(HIR+stone->name()+"��Ϊһ����⣬����"NOR+HIR+ob->name()+"�İ����С�\n"NOR,this_object());
	if( h-1 == 0){
		ob->add("level",1);
		if( j+1 == 2 ) ob->set("name",name+HIM"��"NOR);
		if( j+1 == 5 ) ob->set("name",name+HIM"��"NOR);
		if( j+1 == 8 ) ob->set("name",name+HIM"��"NOR);
		if( j+1 == 9 ) ob->set("name","��"+WHT"��������"NOR+"��"+name);
	}
	m=(string)stone->query("����/damage_type");    //�˺�������
	n=(int)stone->query("����/damage");            //�˺��Ĵ�С
	if(n){          //������˺�
		ob->set("����/damage_type",m);
		ob->add("����/damage",n);
	}
	ob->add("add_jade",1);
	ob->add("hole",-1);
	if(j+1 >= 9){
		ob->set("long","�������������"+chinese_number(addjade+1)+"�ű�ʯ��\n�Ա߻��м����֣�"+me->name()+"\n"); 
		CHANNEL_D->do_sys_channel(
                "info",sprintf("%s��%s�ϳ�����������:%s", NATURE_D->game_time(),me->name(), ob->name()) );  
        }                       
	else
		ob->set("long","���������"+chinese_number(addjade+1)+"�ű�ʯ��"+chinese_number(h-1)+"�����ۡ�\n"); 
        ob->save();
        destruct(stone);
        return 1;
}       
