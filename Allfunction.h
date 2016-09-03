`struct Student {  // 需要输入的数据的结构体 
    int ID;       //学生ID 
    char name[20];  // 学生姓名 
    int class_;     // 学生班级 
    int grade;     // 学生年级 
    int score;     // 学生分数 
    char if_exist; // 判断这是不是一个存在的数据，删除学生成绩时用，0即不存在，1即存在 
};

//最初的匹配用户的命令并执行 ，匹配并打印无需返回值 
void requi_swit_main(int );

//判断用户最初的输入是否符合要求，不符合继续输入直到符合 
void judge_ifvalid(int * );

// 打印添加学生信息的指令，获取用户输入的学生信息 
void append_record();

// 打开一个文件，并获取其中储存的学生的信息 
long openfile(struct Student * studenttemp);

// 把学生的信息写入文件 
void writefile(int, struct Student * studenttemp); 

// 通过ID查询一个学生的所有信息 ,获取学生ID在函数内部，所以无返回值无形参列表 
void consult(); 

// 获取删除学生信息的不同指令的总函数 
void delete_number();

// 删除一个年级的信息 
void grade_delete(int grade, int filelength, struct Student * stu); 

// 删除一个班级的信息 
void cla_delete(int class_, int grade, int filelength, struct Student * stu);

// 删除一个学生的信息 ,如果成功删除返回1，其他返回0 
int id_delete(int id, int filelength, struct Student * stu);

// 获取需要修改的学生ID，打印需要修改不同信息的指令并获取 
void modify();

//  打印功能选项，并获取用户需要，根据用户的选择获取需要的输入调用不同函数进行修改 
void query(); 

// 获取一个班级最高分，并且该最高分学生的ID，如果有两个学生都是最高分只会得到第一个的ID ,这些输出都可以在函数中完成不需要返回值 
void  get_max(long all_num, int grade, int class_, struct Student * stu);

// 获取一个班级最低分，并且获取该学生的ID，如果有两个学生都是最低分只会得到第一个的ID， 这些输出都可以在函数中完成不需要返回值 
void get_min(long all_num, int grade, int class_,  struct Student * stu);

// 获取一个班级的平均分， 这些输出都可以在函数中完成不需要返回值 
void aver(long all_num, int grade, int class_, struct Student * stu);

// 获取一个班级低于某一个分数的学生的ID， 这些输出都可以在函数中完成不需要返回值 
void down(long all_num, int grade, int class_, int score, struct Student * stu); 

// 获取一个班级高于某一个分数的学生ID ， 这些输出都可以在函数中完成不需要返回值 
void up(long all_num, int grade, int class_, int score, struct Student * stu); 
`
