#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Empleado
{
private:
	int numero_carnet;
	string nombre;
	int fecha_nacimiento;
	string categoria;
	int salario;
	string direccion;
	int telefono;
	string correo;


public:
	vector<int>codigo_Proyectos;

	Empleado(int _numero_carnet, string _nombre, int _fecha, string _categoria, int _salario, string _direccion, int _telefono, string _correo)
	{
		this->numero_carnet = _numero_carnet;
		this->nombre = _nombre;
		this->fecha_nacimiento = _fecha;
		this->categoria = _categoria;
		this->salario = _salario;
		this->direccion = _direccion;
		this->telefono = _telefono;
		this->correo = _correo;
	}

	void actualizarDatos(string _nombre, int _fecha, string _categoria, int _salario, string _direccion, int _telefono, string _correo)
	{
		this->nombre = _nombre;
		this->fecha_nacimiento = _fecha;
		this->categoria = _categoria;
		this->salario = _salario;
		this->direccion = _direccion;
		this->telefono = _telefono;
		this->correo = _correo;
	}
	void mostrarDatos()
	{

		cout << "Nombre del Empleado: " << nombre << endl;
		cout << "Fecha de nacimiento: " << fecha_nacimiento << endl;
		cout << "Categoria: " << categoria << endl;
		cout << "Salario: " << salario << endl;
		cout << "Direccion: " << direccion << endl;
		cout << "Telefono: " << telefono << endl;
		cout << "Correo: " << correo << endl;
	}

	int getNumeroCarnet()
	{
		return numero_carnet;
	}

	string getNombre()
	{
		return nombre;
	}


};

class Proyecto
{
private:
	int codigo;
	string nombre;
	string fecha_inicio;
	string fecha_finalización;


public:
	vector<int>nombre_integrantes;
	Proyecto(int _codigo, string _nombre, string _fecha_inicio, string _fecha_finalización)
	{
		this->codigo = _codigo;
		this->nombre = _nombre;
		this->fecha_inicio = _fecha_inicio;
		this->fecha_finalización = _fecha_finalización;
	}
	void actualizarDatos(int _codigo, string _nombre, string _fecha_inicio, string _fecha_finalización)
	{
		this->codigo = _codigo;
		this->nombre = _nombre;
		this->fecha_inicio = _fecha_inicio;
		this->fecha_finalización = _fecha_finalización;
	}
	void mostrarDatos()
	{
		cout << "Codigo del Proyecto: " << codigo << endl;
		cout << "Nombre del Proyecto: " << nombre << endl;
		cout << "Fecha de inicio: " << fecha_inicio << endl;
		cout << "Fecha de finalización: " << fecha_finalización << endl;
	}

	int getCodigo()
	{
		return codigo;
	}
	
	string getNombre()
	{
		return nombre;
	}

};

class Gestion {

	private:
		vector<Empleado> empleados;
		vector<Proyecto> proyectos;
		vector<string> correos;
		vector<string> nombres;

	public:
		void agregarEmpleado()
		{
			int numero_carnet, salario, telefono,fecha_nacimiento, edad;
			string nombre,categoria,direccion,correo;


			cout << "Ingrese el numero de carnet: ";
			cin >> numero_carnet;
			cout << "Ingrese el nombre: ";
			cin.ignore(); getline(cin, nombre);
			cout << "Ingrese el telefono: ";
			cin >> telefono;

			while (true)
			{
				cout << "Ingrese la categoria( Administrador, Operario, Peon): ";
				getline(cin, categoria);

				if (categoria == "Administrador" || categoria == "Operario" || categoria == "Peon")
				{
					break;
				}
				else
				{
					cout << "La categoria debe ser Administrador, Operario o Peon" << endl;
				}

			}


				cout << "Ingrese la direccion: ";
				cin.ignore(); getline(cin, direccion);

				if (direccion == "")
				{
					direccion = "San Jose";
					
				}

			

			while (true)
			{
				cout << "Ingrese la fecha de nacimiento: ";
				cin >> fecha_nacimiento;
				edad = 2024 - fecha_nacimiento;
				if (edad >= 18)
				{
					break;
				}
				else
				{
					cout << "La edad debe ser mayor o igual a 18" << endl;
				}
			}

			while (true)
			{

				cout << "Ingrese el salario: ";
				cin >> salario;

				if (salario < 250000 || salario > 500000)
				{
					cout << "El salario debe estar entre 250000 y 500000" << endl;
				}
				else if (salario == NULL)
				{
					salario = 250000;
				}
				else
				{
					break;
				}
			}

			while (true)
			{
				cout << "Ingrese el correo: ";
				cin.ignore(); getline(cin, correo); 

				for (int i = 0; i < correos.size(); i++)
				{
					if (correos[i] == correo)
					{
						cout << "El correo ya existe" << endl;
					}
				}
				
				
				correos.push_back(correo);	
				break;
			}
			

			Empleado empleado(numero_carnet, nombre, fecha_nacimiento, categoria, salario, direccion, telefono, correo);
			empleados.push_back(empleado); 

			cout << "Empleado registrado con exito\n";
		}

		void mostrarEmpleados()
		{
			if (empleados.empty())
			{
				cout << "No hay empleados registrados\n";
			}
			else
			{
				for (int i = 0; i < empleados.size(); i++)
				{
					cout << "Empleado " << i + 1 << endl;
					empleados[i].mostrarDatos();
					cout << "=============================\n";
				}
			}
		}

		void actualizarEmpleado()
		{
			int salario, telefono, fecha_nacimiento, edad;
			string nombre, categoria, direccion, correo;
			bool find = false;

			if (empleados.empty())
			{
				cout << "No hay empleados registrados\n";
			}
			else
			{
				int numero;
				cout << "Ingrese el numero de carnet del empleado a actualizar: ";
				cin >> numero;

				for (int i = 0; i < empleados.size(); i++)
				{
					if (empleados[i].getNumeroCarnet() == numero)
					{
						find = true;
						cout << "Ingrese el nuevo nombre: ";
						cin.ignore(); getline(cin, nombre);
						cout << "Ingrese el nuevo telefono: ";
						cin >> telefono;

						while (true)
						{
							cout << "Ingrese la nueva categoria( Administrador, Operario, Peon): ";
							getline(cin, categoria);

							if (categoria == "Administrador" || categoria == "Operario" || categoria == "Peon")
							{
								break;
							}
							else
							{
								cout << "La categoria debe ser Administrador, Operario o Peon" << endl;
							}

						}

						while (true)
						{
							cout << "Ingrese la nueva direccion: ";
							cin.ignore(); getline(cin, direccion);

							if (direccion == "")
							{
								direccion = "San Jose";

							}
							else
							{
								break;
							}
						}

						while (true)
						{
							cout << "Ingrese la nueva fecha de nacimiento: ";
							cin >> fecha_nacimiento;
							edad = 2024 - fecha_nacimiento;
							if (edad >= 18)
							{
								break;
							}
							else
							{
								cout << "La edad debe ser mayor o igual a 18" << endl;
							}
						}

						while (true)
						{

							cout << "Ingrese el nuevo salario: ";
							cin >> salario;

							if (salario < 250000 || salario > 500000)
							{
								cout << "El salario debe estar entre 250000 y 500000" << endl;
							}
							else if (salario == NULL)
							{
								salario = 250000;
							}
							else
							{
								break;
							}
						}

						while (true)
						{
							cout << "Ingrese el nuevo correo: ";
							cin.ignore(); getline(cin, correo);

							for (int i = 0; i < correos.size(); i++)
							{
								if (correos[i] == correo)
								{
									cout << "El correo ya existe" << endl;
								}
							}

							correos.push_back(correo);
							break;

						}
					}
				}
				if (find == false)
				{
					cout << "No se encontro el empleado\n";
				}
			}
		}

		void agregarProyecto()
		{
			int codigo;
			string nombre, fecha_inicio, fecha_finalizacion;

			cout << "Ingrese el codigo del proyecto: ";
			cin >> codigo;

			while (true)
			{
				cout << "Ingrese el nombre del proyecto: ";
				cin.ignore(); getline(cin, nombre);

				for (int i = 0; i < nombres.size(); i++)
				{
					if (nombres[i] == nombre)
					{
						cout << "El nombre ya existe" << endl;
					}
				}

				nombres.push_back(nombre);
				break;

			}

			cout << "Ingrese la fecha de inicio: ";
			cin.ignore(); getline(cin, fecha_inicio);
			cout << "Ingrese la fecha de finalizacion: ";
			cin.ignore(); getline(cin, fecha_finalizacion);

			Proyecto proyecto(codigo, nombre, fecha_inicio, fecha_finalizacion);
			proyectos.push_back(proyecto);

			cout << "Proyecto registrado con exito\n";
		}

		void mostrarProyectos()
		{
			if (proyectos.empty())
			{
				cout << "No hay proyectos registrados\n";
			}
			else
			{
				for (int i = 0; i < proyectos.size(); i++)
				{
					cout << "Proyecto " << i + 1 << endl;
					proyectos[i].mostrarDatos();
					cout << "=============================\n";
				}
			}
		}

		void actualizarProyecto()
		{
			string nombre, fecha_inicio, fecha_finalizacion;
			bool find = false;

			if (proyectos.empty())
			{
				cout << "No hay proyectos registrados\n";
			}
			else
			{
				int codigo;
				cout << "Ingrese el codigo del proyecto a actualizar: ";
				cin >> codigo;

				for (int i = 0; i < proyectos.size(); i++)
				{
					if (proyectos[i].getCodigo() == codigo)
					{
						find = true;
						while (true)
						{
							cout << "Ingrese el nombre del proyecto: ";
							cin.ignore(); getline(cin, nombre);

							for (int i = 0; i < nombres.size(); i++)
							{
								if (nombres[i] == nombre)
								{
									cout << "El nombre ya existe" << endl;
								}
							}

							nombres.push_back(nombre);
							break;

						}

						cout << "Ingrese la nueva fecha de inicio: ";
						cin.ignore(); getline(cin, fecha_inicio);
						cout << "Ingrese la nueva fecha de finalizacion: ";
						cin.ignore(); getline(cin, fecha_finalizacion);
					}
				}
				if (find == false)
				{
					cout << "No se encontro el proyecto\n";
				}
			}
		}

		void agregarEmpleadoProyecto()
		{
			int numero_carnet, codigo;
			bool findEmpleado = false;
			bool findProyecto = false;

			if (empleados.empty())
			{
				cout << "No hay empleados registrados\n";
			}
			else if (proyectos.empty())
			{
				cout << "No hay proyectos registrados\n";
			}
			else
			{
				cout << "Ingrese el numero de carnet del empleado: ";
				cin >> numero_carnet;
				cout << "Ingrese el codigo del proyecto: ";
				cin >> codigo;

				for (int i = 0; i < empleados.size(); i++)
				{
					if (empleados[i].getNumeroCarnet() == numero_carnet)
					{
						findEmpleado = true;
						for (int j = 0; j < proyectos.size(); j++)
						{
							if (proyectos[j].getCodigo() == codigo)
							{
								findProyecto = true;
								
								for (int k = 0; k < empleados[i].codigo_Proyectos.size(); k++)
								{
									if (empleados[i].codigo_Proyectos[k] == codigo)
									{
										cout << "El empleado ya esta en el proyecto\n";
										break;
									}
								}

								empleados[i].codigo_Proyectos.push_back(codigo);
								proyectos[j].nombre_integrantes.push_back(numero_carnet);
								cout << "Empleado agregado al proyecto\n";



							}
						}
					}
				}
				if (findEmpleado == false)
				{
					cout << "No se encontro el empleado\n";
				}
				else if (findProyecto == false)
				{
					cout << "No se encontro el proyecto\n";
				}
			}
		}

		void mostrarEmpleadosAsignadosProyecto()
		{

			if (empleados.empty())
			{
				cout << "No hay empleados registrados\n";
			}
			else if (proyectos.empty())
			{
				cout << "No hay proyectos registrados\n";
			}
			else
			{
				
				for (int i = 0; i < empleados.size(); i++)
				{
					cout << "Empleado " << i + 1 << endl;
					empleados[i].mostrarDatos();
					cout << "Proyectos asignados: " << endl;
					for (int j = 0; j < empleados[i].codigo_Proyectos.size(); j++)
					{
						for (int k = 0; k < proyectos.size(); k++)
						{
							if (empleados[i].codigo_Proyectos[j] == proyectos[k].getCodigo())
							{
								cout << "Proyecto " << k + 1 << endl;
								proyectos[k].mostrarDatos();
							}
						}
					}
					cout << "=============================\n";

				}

			}

		}

		void mostrarProyectosAsignadosEmpleado()
		{
			if (empleados.empty())
			{
				cout << "No hay empleados registrados\n";
			}
			else if (proyectos.empty())
			{
				cout << "No hay proyectos registrados\n";
			}
			else
			{
				for (int i = 0; i < proyectos.size(); i++)
				{
					cout << "Proyecto " << i + 1 << endl;
					proyectos[i].mostrarDatos();
					cout << "Integrantes: " << endl;
					for (int j = 0; j < proyectos[i].nombre_integrantes.size(); j++)
					{
						for (int k = 0; k < empleados.size(); k++)
						{
							if (proyectos[i].nombre_integrantes[j] == empleados[k].getNumeroCarnet())
							{
								cout << "Empleado " << k + 1 << endl;
								empleados[k].mostrarDatos();
							}
						}
					}
					cout << "=============================\n";
				}
			}
		}

		void menu()
		{
			int opcion;
			do
			{
				system("cls");
				cout << "Gestion de Empleados y Proyectos\n";
				cout << "====================================\n";
				cout << "1. Agregar Empleado\n";
				cout << "2. Mostrar Empleados\n";
				cout << "3. Actualizar Empleado\n";
				cout << "4. Agregar Proyecto\n";
				cout << "5. Mostrar Proyectos\n";
				cout << "6. Actualizar Proyecto\n";
				cout << "7. Agregar Empleado a Proyecto\n";
				cout << "8. Mostrar Empleados asignados a Proyecto\n";
				cout << "9. Mostrar Proyectos asignados a Empleado\n";
				cout << "10. Salir\n";
				cout << "Ingrese una opcion: ";
				cin >> opcion;

				switch (opcion)
				{
				case 1:
					agregarEmpleado();
					system("pause");
					break;
				case 2:
					mostrarEmpleados();
					system("pause");
					break;
				case 3:
					actualizarEmpleado();
					system("pause");
					break;
				case 4:
					agregarProyecto(); 
					system("pause");
					break;
				case 5:
					mostrarProyectos();
					system("pause");
					break;
				case 6:
					actualizarProyecto();
					system("pause");
					break;
				case 7:
					agregarEmpleadoProyecto();
					system("pause");
					break;
				case 8:
					mostrarEmpleadosAsignadosProyecto();
					system("pause");
					break;
				case 9:
					mostrarProyectosAsignadosEmpleado();
					system("pause");
					break;

				case 10:
					cout << "Saliendo...\n";
					system("pause");
					break;
				default:
					cout << "Opcion no valida\n";
					break;
				}

		
			} while (opcion != 10);

		}


};

int main()
{
	Gestion gestion;
	gestion.menu();
	return 0;

}