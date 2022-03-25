
set(EXECSOURCE
	main.cpp

	accQT.cpp
	accQT.h

	cathegorie.cpp
	cathegorie.h

	module.cpp
	module.h
	)

set(UISOURCE
	appfield.cpp
	appfield.h

	mainwindow.cpp
	mainwindow.h
	)

set(SOURCE ${EXECSOURCE} ${UISOURCE})

message(${SOURCE})
add_executable(${PRNAME} ${SOURCE})

foreach (I IN LISTS REQUIRES)
	find_package(QT NAMES Qt6 Qt5      COMPONENTS ${I} REQUIRED)
	find_package(Qt${QT_VERSION_MAJOR} COMPONENTS ${I} REQUIRED)
	target_link_libraries(${PRNAME} PRIVATE Qt${QT_VERSION_MAJOR}::${I})
endforeach()
