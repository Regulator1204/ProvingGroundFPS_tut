// Fill out your copyright notice in the Description page of Project Settings.

#include "TaskChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrolRouteComponent.h"

EBTNodeResult::Type UTaskChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{


	// get patrol points
	auto controlledPawn = OwnerComp.GetAIOwner()->GetPawn();
	auto patrolRouteComp = controlledPawn->FindComponentByClass<UPatrolRouteComponent>();
	if (!ensure(patrolRouteComp))
	{
		return EBTNodeResult::Failed;
	}

	auto patrolPoints = patrolRouteComp->GetPatrolPoints();

	if (patrolPoints.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is missing patrol points!"), *controlledPawn->GetName());
		return EBTNodeResult::Failed;
	}

	// set next waypoint
	UBlackboardComponent* blackboardComp = OwnerComp.GetBlackboardComponent();
	int index = blackboardComp->GetValueAsInt(WaypointIndexKey.SelectedKeyName);
	blackboardComp->SetValueAsObject(NextWaypointKey.SelectedKeyName, patrolPoints[index]);

	// cycle index
	index = (index + 1) % patrolPoints.Num();
	blackboardComp->SetValueAsInt(WaypointIndexKey.SelectedKeyName, index);

	return EBTNodeResult::Succeeded;
}
