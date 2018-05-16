### 内存对齐
为什么最开始的
	
		sizeof(Screen)=16
**因为我的pc是64位的，内存对齐最小是8位的**

然后我们对输出进行解析，每个Screen元素之间的内存最小间隔是16，看图        
![重载operator new和delete](/home/wust_gery/c++_primer/new.png)

但是当我们使用原生的operator new和operator delete 发现元素之间间隔并不是16
![使用原声operatre new和delete](/home/wust_gery/图片/new1.png)
<font color=red size=6>因为cookie占用了空间</font> 

