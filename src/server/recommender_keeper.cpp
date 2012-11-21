// this program is automatically generated by jenerator. do not edit.
#include "../framework/keeper.hpp"
#include "../framework/aggregators.hpp"
#include "../common/exception.hpp"
#include "recommender_types.hpp"
using namespace jubatus;
using namespace jubatus::framework;
int main(int args, char** argv){
  try{
    keeper k(keeper_argv(args,argv,"recommender"));
    k.register_async_broadcast<bool, config_data >("set_config", pfi::lang::function<bool(bool,bool)>(&all_and)); //update
    k.register_async_random<config_data >("get_config"); //pass analysis
    k.register_async_cht<2, bool >("clear_row", pfi::lang::function<bool(bool,bool)>(&all_and)); //update
    k.register_async_cht<2, bool, datum >("update_row", pfi::lang::function<bool(bool,bool)>(&all_and)); //update
    k.register_async_broadcast<bool >("clear", pfi::lang::function<bool(bool,bool)>(&all_and)); //update
    k.register_async_cht<2, datum >("complete_row_from_id", pfi::lang::function<datum(datum,datum)>(&pass<datum >)); //analysis
    k.register_async_random<datum, datum >("complete_row_from_data"); //pass analysis
    k.register_async_cht<2, similar_result, unsigned int >("similar_row_from_id", pfi::lang::function<similar_result(similar_result,similar_result)>(&pass<similar_result >)); //analysis
    k.register_async_random<similar_result, datum, unsigned int >("similar_row_from_data"); //pass analysis
    k.register_async_cht<2, datum >("decode_row", pfi::lang::function<datum(datum,datum)>(&pass<datum >)); //analysis
    k.register_async_broadcast<std::vector<std::string > >("get_all_rows", pfi::lang::function<std::vector<std::string >(std::vector<std::string >,std::vector<std::string >)>(&concat<std::string >)); //analysis
    k.register_async_random<float, datum, datum >("similarity"); //pass analysis
    k.register_async_random<float, datum >("l2norm"); //pass analysis
    k.register_async_broadcast<bool, std::string >("save", pfi::lang::function<bool(bool,bool)>(&all_and)); //update
    k.register_async_broadcast<bool, std::string >("load", pfi::lang::function<bool(bool,bool)>(&all_and)); //update
    k.register_async_broadcast<std::map<std::string,std::map<std::string,std::string > > >("get_status", pfi::lang::function<std::map<std::string,std::map<std::string,std::string > >(std::map<std::string,std::map<std::string,std::string > >,std::map<std::string,std::map<std::string,std::string > >)>(&merge<std::string,std::map<std::string,std::string > >)); //analysis
    return k.run();
  } catch (const jubatus::exception::jubatus_exception& e) {
    std::cout << e.diagnostic_information(true) << std::endl;
    return -1;
  }
}
