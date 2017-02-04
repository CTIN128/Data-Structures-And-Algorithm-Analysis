#include <queue>
#include <iostream>
#include <vector>
#include <limits>

struct Vertex
{
	Vertex(){}
	Vertex(int _Number, int _Dist):Number(_Number), Dist(_Dist) {}
	int Number;
	int Dist = INT_MAX;
	int Path;
};
bool operator<(Vertex p1, Vertex p2)
{
	return p1.Dist > p2.Dist;
}
void PrintPath(int SourceVertex,int vertex, std::vector<Vertex> v)
{
	if (vertex == SourceVertex)
	{
		std::cout << vertex << std::endl;
		return;
	}
	std::cout << vertex << std::endl;
	PrintPath(SourceVertex, v[vertex].Path, v);
}
int main()
{
	int SourceVetex = 0;//����Դ��
	std::vector<Vertex> vec(7);//����������¼����״̬
	vec[SourceVetex].Dist = 0;//Դ�㵽Դ����뵱ȻΪ0
	vec[SourceVetex].Path = SourceVetex;//Դ���Լ�����
	std::priority_queue<Vertex> pq;//�������ȶ��в����ǰ��սڵ��е�dist��С��������
	std::vector<bool> Known(7, false);
	int Graph[][7] =//��������ͼ
	{
	   0,2,0,1,0,0,0,
	   0,0,0,3,10,0,0,
	   4,0,0,0,0,5,0,
	   0,0,2,0,2,8,4,
	   0,0,0,0,0,0,6,
	   0,0,0,0,0,0,0,
	   0,0,0,0,0,1,0
	};
	/*
       for(int i = 0;i < 7;++i)
	   {
	      if(i == SourceVertex)
		    pq.push(Vertex(SourceVertex,0));
		  else
		  pq.push(Vertex(SourceVertx,INT_MAX));
        }
	*/
	pq.push(Vertex(SourceVetex, 0));
	int IsKnown = 0;
	while (!pq.empty())
	{
		Vertex tmpcell = pq.top();
		pq.pop();//������
		IsKnown++;
		Known[tmpcell.Number] = true;
		for (int i = 0; i < 7; ++i)
		{
				if (!Known[i]&&Graph[tmpcell.Number][i] != 0&&vec[tmpcell.Number].Dist + Graph[tmpcell.Number][i] < vec[i].Dist)//������ĵ������������ĵ�Դ��·������ԭ������Դ��·��С�����
				{
					vec[i].Dist = vec[tmpcell.Number].Dist + Graph[tmpcell.Number][i];//����·����
					vec[i].Path = tmpcell.Number;//�����������Ľڵ�
					pq.push(Vertex(i, vec[i].Dist));
					//��pq�е�i��Ӧ�Ĺؼ�ֵ�޸ģ�����STL��û�����ຯ��
				}		
		}
	}
	/*
	  ���㷨���ۿ�֪��pq��Ӧ����ȫ��ѹ�����е㣬Ȼ��Դ�㵽�Լ��ľ���Ϊ0��֮��pq�е���u������u��
	  �ڽӵ㣬ĳ��v���ڵ�Դ������ԭ�ȶ̾͸�����Ϣ����ʱҲҪ��������v��Ӧ�Ĺؼ�ֵ�޸ģ��������STL
	  ����޷��������£���ô������ô�룬��Դ��ΪINT_MAXֵ�ĵ㣬pq��top��Զ����ѡ��������ô�����Ȳ�����Щ��ѹ�뵽�����У�
	  ֻ����Щ�и��µĵ�ѹ�룬����INT_MAX���޸�ʱ�ɽ��õ�ѹ��,�������Ƿ���ʹ����жϣ�
//    ��Ϊ����ÿ�ζ�ѡȡ��Դ����̵ľ��룬��������ֻҪpq(����ÿ���㵽Դ������·��)�е���������㣬�Ǿ����Ѿ�ȷ���õ�ǰ����˭����Դ����̾����ˣ�
//	  �����ٹ�������
	*/
	for (int i = 0; i < 7; ++i)
	{
		std::cout <<"Vertex: "<< i << std::endl;
		std::cout << "Dis: " << vec[i].Dist << std::endl;
		std::cout << "Path: " << std::endl;
		PrintPath(SourceVetex, i, vec);
	}
	return 0;
}