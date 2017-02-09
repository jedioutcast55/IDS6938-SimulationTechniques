#include "helper.hpp"




namespace Tester {

	int mainloop(int  argc , char **  argv  ){
		

		mScene = new Geometry::Scene();
		mParticles = new Geometry::ParticleSystem();

		loadGeometry();

		// Visualizer ------------------------------------------
		try {
			
			nanogui::init();
			{
				
				nanogui::ref<Visualizer::Visualizer> app = new Visualizer::Visualizer();
				app->intialize(mScene);
				app->drawAll();
				app->setVisible(true);
				nanogui::mainloop(1);

				
			}

			nanogui::shutdown();
		}
		catch (const std::runtime_error &e) {
			std::string error_msg = std::string("Caught a fatal error: ") + std::string(e.what());
			#if defined(_WIN32)
			MessageBoxA(nullptr, error_msg.c_str(), NULL, MB_ICONERROR | MB_OK);
			#else
			std::cerr << error_msg << endl;
			#endif
			return -1;
		}

		return 0;
	}
}



int main(int argc, char** argv)
{
	try {
		return Tester::mainloop(argc, argv);
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
		return 1;
	}
	catch (...) {
		std::cout << "Error: unknown exception caught." << std::endl;
		return 1;
	}
}