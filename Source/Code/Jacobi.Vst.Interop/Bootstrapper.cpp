#include "pch.h"
#include "Utils.h"
#include "Bootstrapper.h"

// static helper method
Jacobi::Vst::Core::Plugin::IVstPluginCommandStub^ Bootstrapper::LoadManagedPlugin(System::String^ pluginPath)
{
	// create the plugin (command stub) factory
	auto factory = gcnew Jacobi::Vst::Core::Plugin::ManagedPluginFactory();
	
	// load the managed plugin assembly by its default name
	factory->LoadAssemblyByDefaultName(pluginPath);

	// create the managed type that implements the Plugin Command Stub interface (sends commands to plugin)
	Jacobi::Vst::Core::Plugin::IVstPluginCommandStub^ commandStub = factory->CreatePluginCommandStub();
	
	if(commandStub != nullptr)
	{
		auto basePath = System::IO::Path::GetDirectoryName(pluginPath);
		auto name = System::IO::Path::GetFileNameWithoutExtension(pluginPath);

		auto builder = gcnew Microsoft::Extensions::Configuration::ConfigurationBuilder();
		Microsoft::Extensions::Configuration::FileConfigurationExtensions::SetBasePath(builder, basePath);
		Microsoft::Extensions::Configuration::JsonConfigurationExtensions::AddJsonFile(
			builder, name + ".appsettings.json", /*optional*/ true);
		
		// assign config to commandStub
		commandStub->PluginConfiguration = builder->Build();
	}

	return commandStub;
}
