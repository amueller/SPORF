#ifndef padNode_h
#define padNode_h
//#include <cstdint>
#include <stdio.h>

template <typename T>
class alignas(32) rfNode
{
	protected:
		int left;
		int feature;
		T cutValue;
		int right;

	public:
		inline bool isInternalNode(){
			return left;
		}

		inline T returnCutValue(){
			return cutValue;
		}
		inline T setCutValue(T cVal){
			cutValue = cVal;
		}

		inline int returnFeatureNumber(){
			return feature;
		}

		inline int returnLeftNodeID(){
			return left;	
		}

		inline int returnRightNodeID(){
			return right;
		}

		inline int returnClass(){
			return right;	
		}

		inline void setClass(int classNum){
			right = classNum;
			left = 0;
		}
		inline void setLeftValue(int LVal){
			left = LVal;	
		}
		inline void setRightValue(int RVal){
			right = RVal;
		}

		inline bool goLeft(T featureValue){
			return featureValue < cutValue;
		}

		inline int nextNode(double featureValue){
			return (featureValue < cutValue) ? left : right;
		}

		void virtual printNode(){
			std::cout << "cutValue " << cutValue <<", feature " << feature << ", left " << left << ", right " << right << "\n";
		}

};
#endif //padNode_h
