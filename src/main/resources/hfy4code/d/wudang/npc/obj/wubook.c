 // book.c
inherit ITEM; 
void create()
{
        int     i;
        
        string *names = ({
            "���׾���", "��̫��ȭ�ס�", "��������ͼ��", "��̫���ڹ����š�"
        });
        
        string *skills= ({
            "changelaw", "taiji", "five-steps", "taijiforce"
        });
        
        i = random(4);
        set_name( names[i], ({ "book" }));
        set_weight(100);
        set("unit", "��");
        set("long", "����һ�������䵱�������书���鼮��\n");
        set("skill", ([
            "name":                 skills[i],
            "exp_required": 0,                
            "sen_cost":             50,     
            "difficulty":   50,            
            "max_skill":    100           
                                        
        ]) );
        ::init_item();
}
