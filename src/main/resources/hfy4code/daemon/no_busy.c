 Busy-type we have currently
1.unarmed: 
meihua-shou, dabei-strike, bloodystrike, eagle-claw
2.special-unarmed: 
tanzhi-shentong,taiji,dragonstrike,
3.step: 
nine-moon-steps,fall-steps,hawk-steps,windy-steps,cloud-dance,anxiang-steps,
        fengyu-piaoxiang, meng-steps, jinghong-steps
4.weapon: qingpingsword, three-sword, fumo-staff,
5.special-weapon: taiji-sword
6.specials: alchemy, hong, mihunshu,
7.parry-busy: xiaohun-sword,xiaohun-whip,lingxi-zhi
8.NPC:  shenji-steps,liuquan-steps,  
purpose: 
1.None of the above busy skill can be ����, it should be countered in certain way.
2.Certain NPC, for example bosses, should not be busied easily. 
NPC feature:
(1) BIG Boss: chiyou, hibernating dragon... etc. the busy chance should be no more than 50% for same exp with normal skill,.these guys also can't be zhaixin, can't be ghost-curse, can't be poisoned.
        MARK: set("big_boss",1);
(2) normal boss: dragon lord, octopus, or special NPCs who carries good item, the busy chance should be reduced
        they can't be zhaixin, ghost-curse. or poisoned.
        MARK set("boss",1);
(3) 5M+ new NPCs in 4.1, some of them will have new ability to dodge a certain type of busy. Thus, a player needs to 
        learn more than one busy skill to ensure his power. 
        (a) usually we can skip the 3 unarmed-busy since they have only one real busy time. 
        (b) we should ensure that a menpai has at least one way to deal with enemy. 
        (c) we can exclude those busy with a timer. 
        (d) if a busy isn't strong or it's a symbol of a menpai (alchemy, hong, mihunshu..), leave it alone.
        
        MARK set("step_less",random(2)+1) 
TYPE I: step_less 1 
hawk-steps 
windy-steps 
tanzhi-shentong
qingpingsword 
TYPE II : step_less 2 
fall-steps 
fumostaff
cloud-dance
taiji        
