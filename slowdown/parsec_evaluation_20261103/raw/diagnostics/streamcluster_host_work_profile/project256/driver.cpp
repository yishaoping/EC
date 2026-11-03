extern "C" {void workload_prepare();void workload_run();int workload_verify();} int main(){workload_prepare();workload_run();return !workload_verify();}
