

#include "FilterPipe.h"

FilterPipe::FilterPipe() {

}
void FilterPipe::addFilter(PointCloudFilter *filter) {
	this->filters.push_back(filter);
}
void FilterPipe::filterOut(PointCloud & pc) {

	for (int i = 0; i < filters.size(); i++)
	{
		filters[i]->filter(pc);
	}
}
